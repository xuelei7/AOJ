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
    while (cin >> h >> w, h, w) {
        VV<int> maze(h, V<int>(w));
        rep(i,0,h) {
            rep(j,0,w) {
                cin >> maze[i][j];
            }
        }

        int ret = 0;
        rep(h1,0,h) {
        rep(w1,0,w) {
        rep(h2,h1+2,h) {
        rep(w2,w1+2,w) {
            // calc wall height
            int wall = 1e9;
            rep(i,h1,h2+1) {
                wall = min(wall, maze[i][w1]);
                wall = min(wall, maze[i][w2]);
            }
            rep(i,w1,w2+1) {
                wall = min(wall, maze[h1][i]);
                wall = min(wall, maze[h2][i]);
            }
            // calc pond height
            int pond = 0;
            int size = 0;
            rep(i,h1+1,h2) {
                rep(j,w1+1,w2) {
                    pond = max(pond, maze[i][j]);
                    size += maze[i][j];
                }
            }
            size = (h2-h1-1) * (w2-w1-1) * wall - size;
            // update result
            if (wall > pond) ret = max(ret, size);
        }}}}
        cout << ret << endl;
    }
    
    return 0;
}