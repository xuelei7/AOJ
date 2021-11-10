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
    int h, w, cost, status, end;
    node(int h, int w, int cost, int status, int end): 
        h(h), w(w), cost(cost), status(status), end(end) {}
    bool operator > (const node& other) const {
        return cost > other.cost;
    }
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    int w,h;
    while (cin >> w >> h, w) {
        V<string> maze(h);
        rep(i,0,h) cin >> maze[i];

        V<pair<int,int>> P;
        int sh, sw;
        int sid;
        rep(i,0,h) {
            rep(j,0,w) {
                if (maze[i][j] == '*') P.push_back({i,j});
                if (maze[i][j] == 'o') {
                    sh = i;
                    sw = j;
                    sid = P.size();
                    P.push_back({i,j});
                }
            }
        }

        // cout << "here" << endl;
        int sz = P.size();
        int dh[4] = {-1,0,1,0};
        int dw[4] = {0,1,0,-1};
        auto bfs = [&](int pa, int pb) -> int {
            queue<pair<int,pair<int,int>>> q;
            q.push({0,P[pa]});
            set<pair<int,int>> st;
            st.insert(P[pa]);
            while (!q.empty()) {
                auto tp = q.front(); q.pop();
                if (tp.second == P[pb]) return tp.first;
                rep(i,0,4) {
                    int th = tp.second.first + dh[i];
                    int tw = tp.second.second + dw[i];
                    if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                    if (maze[th][tw] == 'x') continue;
                    if (st.find({th,tw}) != st.end()) continue;
                    q.push({tp.first+1, {th,tw}});
                    st.insert({th,tw});
                }
            }
            return 1e9;
        };
        VV<int> dist(sz,V<int>(sz,1e9));
        rep(i,0,sz) {
            rep(j,0,sz) {
                if (i == j) dist[i][j] = 0;
                else if (j < i) dist[i][j] = dist[j][i];
                else dist[i][j] = bfs(i,j);
            }
        }

        // rep(i,0,sz) {
        //     rep(j,0,sz) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        VV<int> dp((1<<sz),V<int>(sz,1e9));
        dp[1<<sid][sid] = 0;
        priority_queue<node,vector<node>,greater<node>> pq;
        pq.push(node(P[sid].first, P[sid].second, 0, (1<<sid), sid));
        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int cost = tp.cost;
            int status = tp.status;
            int hh = tp.h;
            int ww = tp.w;
            int end = tp.end;

            rep(i,0,sz) {
                if ((status>>i) & 1) continue;
                int c = dist[end][i];
                if (dp[status+(1<<i)][i] > cost + c) {
                    dp[status+(1<<i)][i] = cost + c;
                    pq.push(node(P[i].first, P[i].second, cost+c, status+(1<<i), i));
                }
            }
        }

        int ans = 1e9;
        rep(i,0,sz) {
            ans = min(ans, dp[(1<<sz)-1][i]);
        }
        if (ans == 1e9) cout << -1 << endl;
        else cout << ans << endl;
    }
    
    return 0;
}