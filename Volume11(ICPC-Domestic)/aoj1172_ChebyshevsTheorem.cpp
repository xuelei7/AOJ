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
    
    V<int> v(250000,1);
    v[0] = 0;
    v[1] = 0;
    rep(i,2,250000) {
        if (v[i] == 0) continue;
        int j = i + i;
        while (j < 250000) {
            v[j] = 0;
            j += i;
        }
    }
    rep(i,2,250000) {
        v[i] += v[i-1];
    }

    int n;
    while (cin >> n, n) {
        cout << v[n*2] - v[n] << endl;
    }
    
    return 0;
}