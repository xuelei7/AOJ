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
        char maze[h][w];
        rep(i,0,h) cin >> maze[i];
        VV<bool> flg(h, V<bool>(w));
        int sh, sw;
        rep(i,0,h) {
            rep(j,0,w) {
                if (maze[i][j] == '@') {
                    sh = i;
                    sw = j;
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({sh,sw});
        int dh[4] = {-1,0,1,0};
        int dw[4] = {0,1,0,-1};
        int cnt = 1;
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            rep(i,0,4) {
                int th = tp.first + dh[i];
                int tw = tp.second + dw[i];
                if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                if (maze[th][tw] != '.') continue;
                if (flg[th][tw]) continue;
                q.push({th,tw});
                flg[th][tw] = 1;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}