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
    
    int h,w;
    while (cin >> h >> w, h) {
        V<string> maze(h);
        rep(i,0,h) cin >> maze[i];
        map<char, pair<int,int>> mp;
        rep(i,0,h) {
            rep(j,0,w) {
                mp[maze[i][j]] = {i,j};
            }
        }
        pair<int,int> pos = {0,0};
        string str;
        cin >> str;
        int ret = 0;
        rep(i,0,str.size()) {
            auto nxtpos = mp[str[i]];
            ret += abs(nxtpos.first - pos.first) + abs(nxtpos.second - pos.second) + 1;
            pos = nxtpos;
        }
        cout << ret << endl;
    }
    
    return 0;
}