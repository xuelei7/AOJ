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
    double R;
    while (cin >> R >> n, R > 0.5) {
        V<double> height(50);
        rep(i,0,n) {
            int x1,x2;
            double h;
            cin >> x1 >> x2 >> h;
            x1 += 25; x2 += 25;
            rep(j,x1,x2) {
                height[j] = max(height[j], h);
            }
        }
        // rep(i,25-R,25+R) cout << height[i] << " ";
        // cout << endl;

        double l = 0, r = 25;
        for (int cnt = 0; cnt < 60; cnt++) {
            double mid = (l + r) / 2.0;
            bool ok = 1;

            // cout << mid << ": ";
            rep(i,25-R,25+R) {
                // left
                double hh;
                if (i < 25) {
                    hh = sqrt(R * R - (24-i) * (24-i));
                } else { // right
                    hh = sqrt(R * R - (i-25) * (i-25));
                }
                hh += -R+mid;
                // cout << i-25 << "," << hh << "," << height[i] << "; ";
                if (hh > height[i]) {
                    ok = 0;
                    break;
                }
            }
            // cout << endl;

            if (ok) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << fixed << setprecision(4) << l << endl;
    }
    
    return 0;
}