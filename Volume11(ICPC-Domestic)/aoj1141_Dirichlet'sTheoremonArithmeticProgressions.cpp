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
    
    int a,d,n;
    V<bool> prime(1000010, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i <= 1e6; i++) {
        if (!prime[i]) continue;
        int j = i + i;
        while (j <= 1e6) {
            prime[j] = 0;
            j += i;
        }
    }
    while (cin >> a >> d >> n, a, d, n) {
        while (1) {
            if (prime[a]) n--;
            if (n == 0) {
                cout << a << endl;
                break;
            }
            a += d;
        }
    }
    
    return 0;
}