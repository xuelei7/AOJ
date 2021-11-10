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
    int a[5] = {5,7,5,7,7};
    while (cin >> n, n) {
        V<int> v;
        while (n--) {
            string s;
            cin >> s;
            v.push_back(s.size());
        }
        bool finish = 0;
        for (int i = 0; i < v.size(); i++) {
            int idx = 0;
            int left = a[idx];
            int pos = i;
            bool ok = 1;
            while (1) {
                if (v[pos] > left) {
                    ok = 0;
                    break;
                }
                left -= v[pos];
                if (left == 0) {
                    idx++;
                    if (idx == 5) {
                        cout << i+1 << endl;
                        finish = 1;
                        break;
                    } else {
                        left = a[idx];
                    }
                }
                pos++;
            }
            if (finish) break;
        }
    }
    
    return 0;
}