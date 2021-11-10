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
    
    int n,m;
    while (cin >> n >> m, n, m) {
        int ans = 0;
        VV<int> v(m, V<int>(n));
        rep(i,0,m) {
            rep(j,0,n) {
                cin >> v[i][j];
            }
        }
        rep(i,0,n) {
            int sum = 0;
            rep(j,0,m) {
                sum += v[j][i];
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    
    return 0;
}