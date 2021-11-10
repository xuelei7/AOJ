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
    
    V<int> v(1000010,1e9);
    V<int> vv(1000010,1e9);

    v[0] = 0;
    vv[0] = 0;
    rep(i,1,1000010) {
        int mi = 1e9;
        int mii = 1e9;
        int k = 1;
        while (k*(k+1)*(k+2)/6 <= i) {
            mi = min(mi, v[i-k*(k+1)*(k+2)/6]);
            if (k*(k+1)*(k+2)/6%2 == 1) 
                mii = min(mii, vv[i-k*(k+1)*(k+2)/6]); 
            k++;
        }
        v[i] = mi+1;
        vv[i] = mii+1;
    }

    int n;
    while (cin >> n, n) {
        cout << v[n] << " " << vv[n] << endl;
    }


    
    return 0;
}