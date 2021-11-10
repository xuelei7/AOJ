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
    
    string s;
    while (cin >> s) {
        if (s == "#") break;
        int y,m,d;
        cin >> y >> m >> d;
        if (y > 31) {
            cout << "? " << y-30 << " " << m << " " << d << endl;
        } else if (y < 31) {
            cout << s << " " << y << " " << m << " " << d << endl;
        } else {
            if (m <= 4) {
                cout << s << " " << y << " " << m << " " << d << endl;
            } else {
                cout << "? " << y-30 << " " << m << " " << d << endl;
            }
        }
    }
    
    return 0;
}