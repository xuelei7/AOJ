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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int h,w;
    while (cin >> w >> h, w, h) {
        VV<int> tate(h,V<int>(w-1));
        VV<int> yoko(h-1,V<int>(w));
        rep(i,0,h*2-1) {
            if (i&1) {
                rep(j,0,w) cin >> yoko[i/2][j];
            } else {
                rep(j,0,w-1) cin >> tate[i/2][j];
            }
        }

        VV<int> maze(h, V<int>(w, 1e9));
        maze[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int dh[4] = {-1,0,1,0};
        int dw[4] = {0,1,0,-1};
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            int hh = tp.first;
            int ww = tp.second;
            rep(i,0,4) {
                int th = hh + dh[i];
                int tw = ww + dw[i];
                if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                if (maze[th][tw] != 1e9) continue;
                // down
                if (i == 2 && yoko[hh][ww]) continue;
                // right
                if (i == 1 && tate[hh][ww]) continue;
                // up
                if (i == 0 && yoko[hh-1][ww]) continue;
                // left
                if (i == 3 && tate[hh][ww-1]) continue;
                maze[th][tw] = maze[hh][ww] + 1;
                q.push({th,tw});
            }    
        }
        if (maze[h-1][w-1] == 1e9) cout << 0 << endl;
        else cout << maze[h-1][w-1] << endl;
    }
    
    return 0;
}