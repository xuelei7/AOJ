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

struct node {
    double cost;
    int id;
    int status;
    node(int id, int status, double cost): id(id), status(status), cost(cost) {}
    bool operator > (const node& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m,p,a,b;
    while (cin >> n >> m >> p >> a >> b) {
        if (n+m+p+a+b == 0) break;
        a--;
        b--;

        V<double> t(n);
        rep(i,0,n) cin >> t[i];

        VV<pair<int,double>> G(m);
        rep(i,0,p) {
            int f,t;
            double c;
            cin >> f >> t >> c;
            f--;
            t--;
            G[f].push_back({t,c});
            G[t].push_back({f,c});
        }

        VV<double> dp(m, V<double>(1<<n, 1e9));
        priority_queue<node,vector<node>,greater<node>> pq;
        dp[a][(1<<n)-1] = 0;
        pq.push(node(a,(1<<n)-1,0));
        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int from = tp.id;
            double cost = tp.cost;
            int status = tp.status;
            // cout << from << " " << bitset<8>(status) << " " << cost << endl;

            for (int i = 0; i < G[from].size(); i++) {
                int to = G[from][i].first;
                double c = G[from][i].second;
                // if (dp[to][status] > dp[from][status] + c) {
                //     dp[to][status] = dp[from][status] + c;
                //     pq.push(node(to,status,dp[to][status]));
                //     cout << "  " << to << " " << c << endl;
                // }
                rep(j,0,n) {
                    if (!((tp.status >> j) & 1)) continue;
                    double tc = c / t[j];
                    int ts = status - (1<<j);
                    if (dp[to][ts] > dp[from][status] + tc) {
                        dp[to][ts] = dp[from][status] + tc;
                        pq.push(node(to,ts,dp[to][ts]));
                        // cout << "  " << to << " " << tc << endl;
                    }
                }
            }
        }
        double ret = 1e9;
        rep(i,0,(1<<n)) {
            ret = min(ret, dp[b][i]);
        }
        if (ret == 1e9) {
            cout << "Impossible" << endl;
        } else {
            cout << fixed << setprecision(20) << ret << endl;
        }
    }
    
    return 0;
}