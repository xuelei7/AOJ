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
    
    int n,a,b;
    while (cin >> n >> a >> b,n,a,b) {
        V<int> v(n);
        rep(i,0,n) cin >> v[i];
        sort(v.rbegin(), v.rend());
        int mx = 0;
        int ans = 0;
        rep(i,a-1,b) {
            if (v[i] - v[i+1] >= mx) {
                mx = v[i] - v[i+1];
                ans = i+1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}