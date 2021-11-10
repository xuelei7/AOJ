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

int parse(string s, int& pos) {
    // cout << pos << ": " << s[pos] << endl;
    int ret = 0;
    if (s[pos] == '[') {
        pos++;
        V<int> v;
        do {
            v.push_back(parse(s, pos));
        } while (pos < s.size() && s[pos] != ']');
        pos++;
        sort(all(v));
        rep(i,0,(v.size()+1)/2) {
            ret += v[i];
        }
        // rep(i,0,v.size()) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        return ret;
    } else {
        // cout << "here " << pos << ": " << s[pos] << endl;
        while (pos < s.size() && s[pos] != ']') {
            ret *= 10;
            ret += s[pos] - '0';
            pos++;
        }
        // cout << "end  " << pos << ": " << s[pos] << endl;
        return (ret + 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int pos = 0;
        cout << parse(s,pos) << endl;
    }
    
    return 0;
}