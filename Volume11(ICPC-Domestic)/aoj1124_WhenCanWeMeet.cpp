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
    
    int n,q;
    while (cin >> n >> q, n, q) {
        map<int,int> mp;
        rep(i,0,n) {
            int k;
            cin >> k;
            rep(j,0,k) {
                int d;
                cin >> d;
                mp[d]++;
            }
        }
        int mx = 0;
        int ans = 0;
        for (auto p: mp) {
            if (p.second > mx) {
                mx = p.second;
                ans = p.first;
            }
        }
        cout << (mx >= q? ans: 0) << endl;
    }
    
    return 0;
}