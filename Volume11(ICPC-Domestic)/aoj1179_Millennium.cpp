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
    
    int n;
    cin >> n;
    while (n--) {
        int y,m,d;
        cin >> y >> m >> d;
        int ans = 0;
        ans += (y-1) / 3 * (200+195+195) + ((y-1) % 3) * 195;
        ans += (y % 3 == 0? (m-1) * 20: (m-1)/2*39 + ((m-1)%2)*20);
        ans += d - 1;
        cout << 196470 - ans << endl;
    }
    
    return 0;
}