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
    
    int t,d,l;
    while (cin >> t >> d >> l, t) {
        int lft = 0, cnt = 0;
        rep(i,0,t) {
            int x;
            cin >> x;
            if (i == t-1) break;
            if (x >= l) lft = d;
            if (lft > 0) cnt++;
            lft--;
        }
        cout << cnt << endl;
    }
    
    return 0;
}