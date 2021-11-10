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
    
    int n,m,p;
    while (cin >> m >> n >> p, p) {
        V<pair<int,int>> v(n);
        p--;
        rep(i,0,n) {
            cin >> v[i].first >> v[i].second;
            v[i].first--;
            v[i].second--;
        }
        V<bool> used(m+1);
        int cnt = 1;
        used[p] = 1;
        rep(i,0,n) {
            if (!used[v[i].first] && !used[v[i].second]) continue;
            if (!used[v[i].first] && used[v[i].second]) {
                used[v[i].first] = 1;
                cnt++;
            }
            if (used[v[i].first] && !used[v[i].second]) {
                used[v[i].second] = 1;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}