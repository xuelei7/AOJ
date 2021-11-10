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

int calc(string s, int p, int q, int r, int& pos) {
    switch(s[pos++]) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case 'P':
            return p;
        case 'Q':
            return q;
        case 'R':
            return r;
        case '-':
            return 2-calc(s,p,q,r,pos);
        default:
            // pos++; // '('
            int lft = calc(s,p,q,r,pos);
            char c = s[pos++];
            int rt = calc(s,p,q,r,pos);
            pos++; // ')'
            if (c == '*') return min(lft, rt);
            else return max(lft, rt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s;
    while (cin >> s) {
        if (s == ".") break;

        int ans = 0;
        rep(status,0,27) {
            int tmp = status;
            int p = tmp%3;
            tmp/=3;
            int q = tmp%3;
            tmp/=3;
            int r = tmp%3;
            int pos = 0;
            if (calc(s,p,q,r,pos) == 2) ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}