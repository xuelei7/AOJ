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
    
    V<int> v(300100,1);
    v[0] = 0;
    for (int i = 2; i < 300100; i++) {
        if (i % 7 != 1 && i % 7 != 6) {
            v[i] = 0;
            continue;
        }
        if (!v[i]) continue;
        if (i*6 < 300100)
            v[i*6] = 0;
        for (int tmp = 7; ; tmp += 7) {
            if (i*(tmp+1) < 300100)
                v[i*(tmp+1)] = 0;
            else
                break;
            if (i*(tmp+6) < 300100)
                v[i*(tmp+6)] = 0;
            else
                break;
        }
    }

    V<int> vv;
    for (int i = 6; i < 300100; i++) if (v[i]) vv.push_back(i);

    int n;
    while (cin >> n, n != 1) {
        cout << n << ":";
        V<int> ret;
        for (auto e: vv) {
            if (e > n) continue;
            if (n % e == 0) ret.push_back(e);
        }
        for (int i = 0; i < ret.size(); i++) {
            cout << " " << ret[i];
        }
        cout << endl;
    }

    
    return 0;
}