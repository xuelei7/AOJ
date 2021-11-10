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
    while (cin >> n >> m, n) {
        V<ll> a(n);
        V<ll> w(m);
        rep(i,0,n) cin >> a[i];
        rep(i,0,m) cin >> w[i];
        // cout << n << " " << m << ": " << endl;

        set<ll> st;
        ll mx = 1;
        rep(i,0,m) mx *= 3;
        // cout << mx << endl;
        rep(i,0,mx) {
            ll sum = 0;
            int tmp = i;
            rep(j,0,m) {
                sum += (tmp%3-1) * w[j];
                tmp /= 3;
            }
            st.insert(sum);
        }
        // for (auto e: st) {
        //     cout << e << " ";
        // }
        // cout << endl;

        V<ll> dame;
        bool ok = 1;
        rep(i,0,n) {
            if (st.find(a[i]) == st.end()) {
                ok = 0;
                dame.push_back(a[i]);
            }
        }
        if (ok) {
            cout << 0 << endl;
            continue;
        }

        ll ret = 1e18;
        for (auto p: st) {
            ll new_w = abs(p - dame[0]);
            bool f = 1;
            for (auto e: dame) {
                if (st.find(e-new_w) == st.end() && st.find(e+new_w) == st.end()) {
                    f = 0;
                    break;
                }
            }
            if (f == 1) {
                ret = min(ret, new_w);
            }
        }

        if (ret == 1e18) {
            cout << -1 << endl;
        } else {
            cout << ret << endl;
        }
    }
    
    return 0;
}