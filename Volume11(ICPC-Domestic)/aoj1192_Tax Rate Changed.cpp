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
    
    int x,y,s;
    while (cin >> x >> y >> s, x, y, s) {
        int ans = 0;
        rep(i,1,s) {
            rep(j,1,s) {
                int ss = i * (100+x) / 100 + j * (100+x) / 100;
                if (ss == s) {
                    ans = max(ans, i * (100+y) / 100 + j * (100+y) / 100);
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}