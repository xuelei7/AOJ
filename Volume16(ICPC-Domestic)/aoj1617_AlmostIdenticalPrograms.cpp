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

void f(V<string>& strs, V<string>& others, string s) {
    string str = "";
    bool open = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\"') {
            if (open) {
                strs.push_back(str);
            } else {
                others.push_back(str);
            }
            str = "";
            open = !open;
        } else {
            str += s[i];
        }
    }
    if (str.size() == 0) return;
    if (open) strs.push_back(str);
    else others.push_back(str);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s1, s2;
    while (getline(cin,s1)) {
        if (s1 == ".") break;
        V<string> strs1, strs2;
        V<string> other1, other2;
        f(strs1,other1,s1);
        getline(cin,s2);
        f(strs2,other2,s2);

        // for (auto e: strs1) {
        //     cout << e << " ";
        // }
        // cout << endl;
        // for (auto e: strs2) cout << e << " ";
        // cout << endl;
        // for (auto e: other1) cout << e << " ";
        // cout << endl;
        // for (auto e: other2) cout << e << " ";
        // cout << endl;

        if (strs1.size() != strs2.size()) {
            cout << "DIFFERENT" << endl;
            continue;
        }
        if (other1.size() != other2.size()) {
            cout << "DIFFERENT" << endl;
            continue;
        }
        // -1: same, 0: identical, >=1: different
        int flg = 1;
        int diffcnt = 0;
        for (int i = 0; i < strs1.size(); i++) {
            if (strs1[i] != strs2[i]) diffcnt++;
        }
        flg = diffcnt-1;
        // cout << diffcnt << endl;
        for (int i = 0; i < other1.size(); i++) {
            if (other1[i] != other2[i]) {
                flg = 1;
                break;
            }
        }

        cout << (flg<0? "IDENTICAL": (flg>0? "DIFFERENT": "CLOSE")) << endl;

    }
    
    return 0;
}