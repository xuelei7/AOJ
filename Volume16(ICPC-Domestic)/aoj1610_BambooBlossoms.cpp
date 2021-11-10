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
    
    int m,n;
    while (cin >> m >> n, m) {
        V<bool> v(8000000,1);
        while (1) {
            if (v[m]) {
                if (n == 0) {
                    cout << m << endl;
                    break;
                }
                n--;
                int tmp = m+m;
                while (tmp < 8000000) {
                    v[tmp] = 0;
                    tmp += m;
                }
            }
            m++;
        }
    }
    
    return 0;
}