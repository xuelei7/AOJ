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
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int sz = s.size();
        set<string> st;
        for (int i = 1; i < sz; i++) {
            string a = s.substr(0, i);
            string b = s.substr(i, sz - i);
            string ra = a;
            reverse(all(ra));
            string rb = b;
            reverse(all(rb));
            st.insert(a + b);
            st.insert(b + a);
            st.insert(ra + b);
            st.insert(b + ra);
            st.insert(a + rb);
            st.insert(rb + a);
            st.insert(ra + rb);
            st.insert(rb + ra);
        }
        cout << st.size() << endl;
    }
    
    return 0;
}