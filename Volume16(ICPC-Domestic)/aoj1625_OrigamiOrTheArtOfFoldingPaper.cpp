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
    
    int h,w,t,p;
    int sh, sw;
    while (cin >> w >> h >> t >> p, h) {
        int maze[1010][1010] = {};
        // VV<int> maze(1000,V<int>(1000));
        sh = 0, sw = 0;
        rep(i,0,h) rep(j,0,w) maze[i][j] = 1;
        while(t--) {
            int d,c;
            cin >> d >> c;
            // up -> down
            if (d == 2) {
                rep(i,0,c) {
                    rep(j,0,w) {
                        int fh = sh + i;
                        int fw = sw + j;
                        int th = sh + 2 * c - 1 - i;
                        int tw = fw;
                        maze[th][tw] += maze[fh][fw];
                        maze[fh][fw] = 0;
                    }
                }
                sh += c;
            }
            // left -> right
            else {
                rep(i,0,h) {
                    rep(j,0,c) {
                        int fh = sh + i;
                        int fw = sw + j;
                        int th = fh;
                        int tw = sw + 2 * c - 1 - j;
                        maze[th][tw] += maze[fh][fw];
                        maze[fh][fw] = 0;
                    }
                }
                sw += c;
            }
            // rep(i,0,h) {
            //     rep(j,0,w) {
            //         cout << maze[sh+i][sw+j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "---------" << endl;
        }
        while (p--) {
            int x,y;
            cin >> x >> y;
            cout << maze[sh+y][sw+x] << endl;
        }
        // cout << "=========" << endl;
    }
    
    return 0;
}