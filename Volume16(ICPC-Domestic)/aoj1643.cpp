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

char f(string& s, int& pos, V<int>& mp) {
    if (s[pos] == '(') {
        pos++; // '('
        char c1 = f(s, pos, mp);
        char op = s[pos];
        pos++; // '<' or '>'
        char c2 = f(s, pos, mp);
        pos++; // ')'

        if (op == '<') {
            if (mp[c1-'A'] < mp[c2-'A']) return c1;
            else if (mp[c1-'A'] > mp[c2-'A']) return c2;
            else return c1;
        } else { // '>'
            if (mp[c1-'A'] > mp[c2-'A']) return c1;
            else if (mp[c1-'A'] < mp[c2-'A']) return c2;
            else return c1;
        }
    } else {
        return s[pos++];
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    int n;
    ll kai[20] = {};
    kai[0] = 1;
    kai[1] = 1;
    rep(i,2,20) {
        kai[i] = kai[i-1]*i;
    }
    while (cin >> n, n) {

        string s;
        cin >> s;
        string s1, s2;
        cin >> s1 >> s2;

        ll ans = 0;

        rep(i,0,s.size()) {
            char c = s[i]; // output
            rep(j,0,(1<<(s.size()-1))) {
                // decide left and right
                int ad = 0;
                V<int> mp(26); // left = -1, right = 1
                rep(k,0,s.size()-1) {
                    if (k == i) ad++;
                    if ((j>>k) & 1) { // left
                        mp[s[k+ad]-'A'] = -1;
                    } else { // right
                        mp[s[k+ad]-'A'] = 1;
                    }
                }

                // see if this is ok
                bool ok = 1;
                int pos = 0;
                ok &= c == f(s1, pos, mp);
                pos = 0;
                ok &= c == f(s2, pos, mp);

                // add ans
                if (ok) {
                    ll cntl = 0, cntr = 0;
                    rep(k,0,s.size()-1) {
                        if ((j>>k)&1) cntl++;
                        else cntr++;
                    }
                    ans += kai[cntl] * kai[cntr];
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}