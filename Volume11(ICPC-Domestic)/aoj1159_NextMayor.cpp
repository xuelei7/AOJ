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
        V<int> v(n);
        int b = m;
        int pos = 0;
        while (true) {
            if (b != 0) {
                b--;
                v[pos]++;
            } else {
                b += v[pos];
                v[pos] = 0;
            }
            pos++;
            pos %= n;
            if (b == 0 && v[pos] == m) {
                cout << pos << endl;
                break;
            }
        }
    }
    
    return 0;
}