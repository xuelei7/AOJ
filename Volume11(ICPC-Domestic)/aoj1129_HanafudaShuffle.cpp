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
    
    int n,r;
    while (cin >> n >> r, n, r) {
        V<int> v(n);
        rep(i,0,n) v[i] = n-i;
        rep(i,0,r) {
            int p,c;
            cin >> p >> c;
            p--;
            V<int> a,b;
            rep(i,0,p) a.push_back(v[i]);
            rep(i,p,p+c) b.push_back(v[i]);
            rep(i,0,c) v[i] = b[i];
            rep(i,0,p) v[i+c] = a[i];
        }
        cout << v[0] << endl;
    }
    
    return 0;
}