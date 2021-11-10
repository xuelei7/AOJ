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

struct Maze{
    int h, w;
    bool maze[25][25] = {};
    int step = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int w,h,gh,gw;
    while (cin >> w >> h, w) {
        Maze mz;
        rep(i,0,h) {
            rep(j,0,w) {
                int x;
                cin >> x;
                mz.maze[i][j] = x;
                if (x == 2) {
                    mz.h = i;
                    mz.w = j;
                    mz.maze[i][j] = 0;
                }
                if (x == 3) {
                    gh = i;
                    gw = j;
                }
            }
        }

        int ret = -1;
        bool goal = 0;
        queue<Maze> q;
        q.push(mz);
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            if (tp.step == 10) break;
            
            // cout << tp.step << endl;
            // rep(i,0,h) {
            //     rep(j,0,w) {
            //         if (i == tp.h && j == tp.w) cout << 2 << " ";
            //         else cout << tp.maze[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "--------------" << endl;

            int dh[4] = {-1,0,1,0};
            int dw[4] = {0,1,0,-1};

            rep(i,0,4) {
                int th = tp.h;
                int tw = tp.w;
                int stepcnt = 0;
                bool ok = 1;
                while (1) {
                    if (th + dh[i] < 0 || th + dh[i] >= h || tw + dw[i] < 0 || tw + dw[i] >= w) {
                        ok = 0;
                        break;
                    }
                    if (th+dh[i] == gh && tw+dw[i] == gw) {
                        goal = 1;
                        ret = tp.step + 1;
                        break;
                    } 
                    if (tp.maze[th+dh[i]][tw+dw[i]] == 0) {
                        th += dh[i];
                        tw += dw[i];
                        stepcnt++;
                    } else {
                        if (stepcnt == 0)
                            ok = 0;
                        break;
                    }
                }
                if (goal) break;
                if (!ok) continue;
                auto nxtmz = tp;
                nxtmz.h = th;
                nxtmz.w = tw;
                nxtmz.maze[th+dh[i]][tw+dw[i]] = 0;
                nxtmz.step++;
                q.push(nxtmz);
            }
            if (goal) break;
        }
        cout << ret << endl;
    }
    
    return 0;
}