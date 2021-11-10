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
    while (cin >> n >> m, n, m) {
        V<int> v1(n), v2(m);
        int sum1 = 0, sum2 = 0;
        rep(i,0,n) {
            cin >> v1[i];
            sum1 += v1[i];
        }
        rep(i,0,m) {
            cin >> v2[i];
            sum2 += v2[i];
        }
        map<int, pair<int,int>> mp;
        rep(i,0,n) {
            rep(j,0,m) {
                int df = v1[i] - v2[j];
                int s = v1[i] + v2[j];
                if (mp.find(df) != mp.end()) {
                    int ss = mp[df].first + mp[df].second;
                    if (s < ss) {
                        mp[df] = {v1[i], v2[j]};
                    }
                } else {
                    mp[df] = {v1[i], v2[j]};
                }
            }
        }
        int df = sum1 - sum2;
        if (df % 2 != 0) {
            cout << -1 << endl;
            continue;
        }
        if (mp.find(df/2) == mp.end()) {
            cout << -1 << endl;
            continue;
        }
        cout << mp[df/2].first << " " << mp[df/2].second << endl;
    }
    
    return 0;
}