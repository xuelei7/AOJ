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
    
    V<pair<int,pair<int,int>>> v;
    for (int i = 1; i <= 200; i++) {
        for (int j = i+1; j <= 200; j++) {
            v.push_back({i*i+j*j, {i,j}});
        }
    }
    sort(all(v));
    map<pair<int,int>, int> mp;
    for (int i = 0; i < v.size(); i++) {
        mp[{v[i].second}] = i;
    }

    int h,w;
    while (cin >> h >> w, h, w) {
        int idx = mp[{h,w}];
        cout << v[idx+1].second.first << " " << v[idx+1].second.second << endl;
    }
    return 0;
}