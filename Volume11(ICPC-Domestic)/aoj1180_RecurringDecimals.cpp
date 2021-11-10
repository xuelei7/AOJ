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

string encode(int a, int l) {
    string ret = "";
    while (l--) {
        ret += a % 10 + '0';
        a /= 10;
    }
    reverse(all(ret));
    return ret;
}

int decode(string s){
    int ret = 0;
    for (auto p: s) {
        ret *= 10;
        ret += p - '0';
    }
    return ret;
}

string f(string s, int l) {
    sort(all(s));
    string rs = s;
    reverse(all(rs));
    return encode(decode(rs) - decode(s), l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int a,l;
    while (cin >> a >> l,a,l) {
        map<string,int> mp;
        mp[encode(a,l)] = 0;
        string pre = encode(a,l);
        int idx = 0;
        while (1) {
            idx++;
            string ret = f(pre, l);
            if (mp.find(ret) != mp.end()) {
                cout << mp[ret] << " " << decode(ret) << " " << idx - mp[ret] << endl;
                break;
            } else {
                mp[ret] = idx;
            }
            pre = ret;
        }
    }
    
    return 0;
}