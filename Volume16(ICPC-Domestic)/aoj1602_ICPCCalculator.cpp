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

int depth(string s) {
    int cnt = 0;
    while (cnt < s.size() && s[cnt] == '.') cnt++;
    return cnt;
}

int calc(V<string>& v, int& pos, int dep) {
    // cout << pos << " " << dep << ": " << v[pos] << endl;
    char c = v[pos][dep];
    if (c >= '0' && c <= '9') {
        return c-'0';
    }

    stack<int> stk;
    while (pos+1 < v.size() && depth(v[pos+1]) == dep + 1) {
        pos++;
        stk.push(calc(v, pos, dep+1));
    }

    int ret = 0;
    if (c == '+') {
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
    }
    else {
        ret = 1;
        while (!stk.empty()) {
            ret *= stk.top();
            stk.pop();
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n, n) {
        V<string> v(n);
        int pos = 0;
        rep(i,0,n) cin >> v[i];
        cout << calc(v,pos,0) << endl;
    }
    
    return 0;
}