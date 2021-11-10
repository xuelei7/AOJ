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
        int hmi = 0, hma = 0, wmi = 0, wma = 0;
        int dh[4] = {0,-1,0,1};
        int dw[4] = {-1,0,1,0};
        V<pair<int,int>> v;
        v.push_back({0,0});
        rep(i,0,n-1) {
            int tn, td;
            cin >> tn >> td;
            int h = v[tn].first + dh[td];
            int w = v[tn].second + dw[td];
            hmi = min(h, hmi);
            wmi = min(w, wmi);
            hma = max(h, hma);
            wma = max(w, wma);
            v.push_back({h,w});
        }
        int w = wma - wmi + 1;
        int h = hma - hmi + 1;
        cout << w << " " << h << endl;
    }
    
    return 0;
}