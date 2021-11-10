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
    
    int w,h;
    while (cin >> w >> h, w, h) {
        VV<int> maze(h, V<int>(w));
        rep(i,0,h) {
            rep(j,0,w) {
                cin >> maze[i][j];
            }
        }
        VV<bool> flg(h, V<bool>(w));
        int cnt = 0;
        int dh[8] = {-1,0,1,0,1,1,-1,-1};
        int dw[8] = {0,1,0,-1,1,-1,1,-1};

        function<void(int,int)> dfs = [&](int hh, int ww) {
            rep(i,0,8) {
                int th = hh + dh[i];
                int tw = ww + dw[i];
                if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                if (!maze[th][tw] || flg[th][tw]) continue;
                flg[th][tw] = 1;
                dfs(th, tw);
            }
        };
        
        rep(i,0,h) {
            rep(j,0,w) {
                if (!maze[i][j]) continue;
                if (flg[i][j]) continue;
                flg[i][j] = 1;
                dfs(i,j);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


