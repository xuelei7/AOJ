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

string ecd(int k, string s) {
    string ret = "";
    if (k == 1) ret = s;
    if (k > 1) ret = to_string(k) + s;
    return ret;
}

string encode(int k) {
    string ret = "";
    int m = k / 1000;
    k %= 1000;
    int c = k / 100;
    k %= 100;
    int x = k / 10;
    k %= 10;
    int i = k;

    ret += ecd(m, "m");
    ret += ecd(c, "c");
    ret += ecd(x, "x");
    ret += ecd(i, "i");
    return ret;
}

int decode(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        int k = 1;
        if (s[i] >= '2' && s[i] <= '9') {
            k = s[i] - '0';
            i++;
        }
        if (s[i] == 'm') k *= 1000;
        if (s[i] == 'c') k *= 100;
        if (s[i] == 'x') k *= 10;
        ret += k;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    cin >> n;
    while(n--) {
        string a,b;
        cin >> a >> b;
        cout << encode(decode(a) + decode(b)) << endl;
    }    
    
    return 0;
}