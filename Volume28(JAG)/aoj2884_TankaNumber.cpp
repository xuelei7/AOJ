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

ll cb[60][60];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    cb[0][0] = 1;
    rep(i,1,56) {
        rep(j,0,i+1) {
            // cout << i << " " << j << endl;
            cb[i][j] = cb[i-1][j];
            if (j-1 >= 0)
                cb[i][j] += cb[i-1][j-1];
            // cout << cb[i][j] << endl;
        }
    }
    // cout << "here" << endl;

    ll n;
    while (cin >> n, n) {
        int keta = 2;
        ll sum = 0;
        int a = 1;
        int b = 0;
        while (1) { // a + (keta-1) * {a/b}
            ll s = 0;
            if (a != b) {
                s = pow(2,keta-1)-1;
        cout << keta << " " << a << " " << b << " " << sum << " " << s << endl;
        cout << sum+s << " vs " << n << endl;
            if (sum + s >= n) break;
            sum += s;
            }
            b++;
            if (b == 10) {
                a++;
                b = 0;
            }
            if (a == 10) {
                keta++;
                a = 1;
            }
        }

        cout << "half: " << sum << " " << keta << " " << a << " " << b << endl;

        V<int> ret;
        ret.push_back(a);
        bool both = 0;
        keta--;
        while (keta) {
        for (auto p: ret) {
            cout << p;
        }
        cout << endl;
            ll s = 0;
            // min(a,b)
            if (!both && min(a,b) == a) {
                rep(k,1,keta-1+1) {
                    s += cb[keta-1][k];
                }
                if (sum + s >= n) {
                    keta--;
                    ret.push_back(min(a,b));
                    continue;
                }
            } else {
                s = pow(2,keta-1);
                if (sum + s >= n) {
                    keta--;
                    ret.push_back(min(a,b));
                    both = 1;
                    continue;
                }
            }
            keta--;
            sum += s;
            ret.push_back(max(a,b));
            if (max(a,b) != a) both = 1;
        }
        for (auto p: ret) {
            cout << p;
        }
        cout << endl;
    }
    
    return 0;
}