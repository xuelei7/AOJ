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
    // constexpr char endl = '\n';
    string s;
    string ss = "([])";
    while (getline(cin, s)) {
        if (s.size() == 1) break;
        V<int> v;
        for (auto c: s) {
            for (int i = 0; i < 4; i++) {
                if (c == ss[i]) v.push_back(i);
            }
        }
        stack<int> stk;
        bool ok = 1;
        for (auto p: v) {
            if (p < 2) {
                stk.push(p);
            } else {
                if (stk.empty()) {
                    ok = 0;
                    break;
                } else if (stk.top() + p != 3) {
                    ok = 0;
                    break;
                } else {
                    stk.pop();
                }
            }
        }
        if (!stk.empty()) ok = 0;
        cout << (ok? "yes" : "no") << endl;
    }
    
    return 0;
}