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
    
    int n,l,r;
    while (cin >> n >> l >> r, n) {
        V<int> v(n+1);
        rep(i,1,n+1) {
            cin >> v[i];
        }
        int cnt = 0;
        rep(i,l,r+1) {
            bool ok = 0;
            rep(j,1,n+1) {
                if (i % v[j] == 0) {
                    if (j % 2 == 1) {
                        cnt++;
                    }
                    ok = 1;
                    break;
                }
            }
            if (!ok && n % 2 == 0) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}