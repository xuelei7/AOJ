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

enum Foot {
    LEFT,
    RIGHT
};

struct node {
    int cost;
    int h, w;
    Foot foot;
    node(int h, int w, int cost, Foot foot): h(h), w(w), cost(cost), foot(foot) {}
    bool operator > (const node& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int w,h;
    while (cin >> w >> h, w) {
        VV<char> mazec(h,V<char>(w));
        VV<int> maze(h,V<int>(w));
        rep(i,0,h) {
            rep(j,0,w) {
                cin >> mazec[i][j];
                maze[i][j] = mazec[i][j] - '0';
                if (mazec[i][j] == 'S') maze[i][j] = 0;
                if (mazec[i][j] == 'T') maze[i][j] = 0;
                if (mazec[i][j] == 'X') maze[i][j] = 1e9;
            }
        }

        priority_queue<node,vector<node>,greater<node>> pq;
        VV<V<int>> dp(h, VV<int>(w,V<int>(2,1e9)));
        rep(i,0,h) {
            rep(j,0,w) {
                if (mazec[i][j] == 'S') {
                    dp[i][j][0] = dp[i][j][1] = 0;
                    pq.push(node(i,j,0,LEFT));
                    pq.push(node(i,j,0,RIGHT));
                }
            }
        }

        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int baseh = tp.h;
            int basew = tp.w;
            Foot foot = tp.foot;
            int cost = tp.cost;
            if (tp.foot == LEFT) {
                basew++;
            } else {
                basew--;
            }

            rep(dh,-2,3) {
                rep(dw,-2,3) {
                    if (abs(dh)+abs(dw) >= 3) continue;
                    int th = baseh + dh;
                    int tw = basew + dw;
                    if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                    if (foot == LEFT && dw < 0) continue;
                    if (foot == RIGHT && dw > 0) continue;

                    int tc = cost + maze[th][tw];
                    if (dp[th][tw][(1-foot)] <= tc) continue;
                    dp[th][tw][(1-foot)] = tc;
                    pq.push(node(th,tw,dp[th][tw][1-foot],(Foot)(1-foot)));
                }
            }
        }

        int ans = 1e9;
        rep(i,0,h) {
            rep(j,0,w) {
                if (mazec[i][j] == 'T') {
                    ans = min(ans, dp[i][j][0]);
                    ans = min(ans, dp[i][j][1]);
                }
            }
        }

        if (ans == 1e9) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }

    }
    
    return 0;
}