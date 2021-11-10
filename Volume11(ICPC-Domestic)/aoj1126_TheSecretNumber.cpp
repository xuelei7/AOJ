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
        V<string> maze(h);
        rep(i,0,h) cin >> maze[i];
        VV<string> mx(h,V<string>(w));
        rep(hh,0,h) {
            rep(ww,0,w) {
                if (maze[hh][ww] < '0' || maze[hh][ww] > '9') continue;
                string str = "";
                if (hh >= 1) {
                    str = mx[hh-1][ww];
                }
                if (ww >= 1) {
                    if (mx[hh][ww-1].size() > str.size()) {
                        str = mx[hh][ww-1];
                    } else if (mx[hh][ww-1].size() == str.size()) {
                        str = max(str, mx[hh][ww-1]);
                    }
                }
                while (str[0] == '0') str = str.substr(1,str.size()-1);
                mx[hh][ww] = str + maze[hh][ww];
            }
        }

        string ret = "";
        rep(hh,0,h) {
            rep(ww,0,w) {
                if (mx[hh][ww].size() > ret.size()) {
                    ret = mx[hh][ww];
                } else if (mx[hh][ww].size() == ret.size()) {
                    ret = max(ret, mx[hh][ww]);
                }
            }
        }
        cout << ret << endl;
    }
    
    return 0;
}