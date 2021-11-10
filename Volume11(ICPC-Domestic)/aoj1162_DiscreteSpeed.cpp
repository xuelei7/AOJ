#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

struct path {
    double d;
    int t, c;
    path(int t, int d, double c):t(t), d(d), c(c) {}
};

int MAX_SPEED = 32;
int MAX_N = 32;

struct status {
    int node, speed, from;
    double time;
    status(int n,int s,int f,double t): node(n), speed(s), from(f), time(t) {}
    bool operator > (const status& other) const {
        return time > other.time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    while (cin >> n >> m, n) {
        // from s, to g
        int s,g;
        cin >> s >> g;
        s--; g--;

        // input paths
        VV<path> G(n);
        rep(i,0,m) {
            int f,t,c;
            double d;
            cin >> f >> t >> d >> c;
            f--; t--;
            G[f].push_back(path(t,d,c));
            G[t].push_back(path(f,d,c));
        }

        // time records
        // dp[node][speed][from]
        V<VV<double>> dp(MAX_N, VV<double>(MAX_SPEED, V<double>(MAX_N, 1e9)));
        dp[s][0][s] = 0;
        priority_queue<status,vector<status>,greater<status>> pq;
        pq.push(status(s,0,s,0));

        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();

            int from = tp.from;
            int speed = tp.speed;
            int node = tp.node;
            double time = tp.time;

            if (time > dp[node][speed][from]) continue;

            rep(dv,-1,2) {
                int new_speed = speed + dv;
                if (new_speed <= 0) continue;
                rep(i,0,G[node].size()) {
                    int to = G[node][i].t;
                    int limit = G[node][i].c;
                    double dist = G[node][i].d;

                    if (new_speed > limit) continue;
                    if (to == from) continue;

                    double new_time = time + dist / new_speed;
                    if (new_time < dp[to][new_speed][node]) {
                        dp[to][new_speed][node] = new_time;
                        pq.push(status(to,new_speed,node,dp[to][new_speed][node]));
                    }
                }
            }
        }
        
        double ans = 1e9;
        rep(i,0,G[g].size()) {
            ans = min(ans, dp[g][1][G[g][i].t]);
        }
        if (ans == 1e9) cout << "unreachable" << endl;
        else cout << fixed << setprecision(20) << ans << endl;
    }
    
    return 0;
}