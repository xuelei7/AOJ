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
    
    ll n;
    while (cin >> n, n) {
        int a = n, k = 1;
        for (ll i = 2; i * i < 2 * n; i++) {
            if ((2*n) % i == 0 && (2*n)/i-i+1 >= 2) {
                int ta = (2*n)/i-i+1;
                if (ta % 2 == 0) {
                    a = ta/2;
                    k = i;
                }
            }
        }
        cout << a << " " << k << endl;
    }
    
    return 0;
}