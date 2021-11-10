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

int hs(string ss, string s, int& pos) {
    if (s[pos] >= 'a' && s[pos] <= 'd') {
        return ss[s[pos++]-'a']-'0';
    }

    if (s[pos] == '[') {
        pos++;
        int val = hs(ss,s,pos);
        pos++;
        return val;
    }

    char c = s[pos];
    pos++;
    int a = hs(ss,s,pos);
    int b = hs(ss,s,pos);
    if (c == '+') {
        return a | b;
    } else if (c == '*') {
        return a & b;
    } else {
        return a ^ b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s;
    while (cin >> s) {
        if (s == ".") break;
        string ss;
        cin >> ss;
        int pos = 0;
        int hash = hs(ss,s,pos);
        string str = "0000";
        int cnt = 0;
        rep(a,0,10) {
            str[0] = '0'+a;
            rep(b,0,10) {
                str[1] = '0'+b;
                rep(c,0,10) {
                    str[2] = '0'+c;
                    rep(d,0,10) {
                        str[3] = '0'+d;
                        pos = 0;
                        if (hash == hs(str,s,pos)) cnt++;
                    }
                }
            }
        }
        cout << hash << " " << cnt << endl;
    }
    
    return 0;
}