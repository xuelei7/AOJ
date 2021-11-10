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
    while (cin >> n, n) {
        V<int> w(n);
        rep(i,0,n) {
            cin >> w[i];
        }
        VV<bool> dp(n+1, V<bool>(n+1));
        rep(i,0,n-1) {
            if (abs(w[i]-w[i+1]) <= 1) dp[2][i] = 1;
        }

        for (int len = 4; len <= n; len += 2) {
            bool ok = 0;
            for(int i = 0; i + len <= n; i++) {
                if (abs(w[i]-w[i+len-1]) <= 1 && dp[len-2][i+1])
                    dp[len][i] = 1;
                for (int l = 2; l <= n; l += 2) {
                    if (dp[l][i] && dp[len-l][i+l]) 
                        dp[len][i] = 1;
                }
                if (dp[len][i]) ok = 1;
            }
        }

        // rep(i,0,n) {
        //     cout << setw(3) << i << ": ";
        //     rep(j,0,n+1) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> v(n+1, -1);
        rrep(i,0,n) {
            for (int len = 2; len <= n; len += 2) {
                if (!dp[len][i]) continue;
                int ed = i + len - 1;
                v[len] = max(v[len], i);
                for (int l = 2; l <= n; l += 2) {
                    if (v[l] > ed) {
                        v[l + len] = max(v[l+len], i);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != -1)
                ans = max(ans, i);
        }
        cout << ans << endl;
    }
    
    return 0;
}