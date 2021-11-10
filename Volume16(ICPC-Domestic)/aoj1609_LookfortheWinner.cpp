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
    
    int n;
    while (cin >> n, n) {
        V<char> c(n);
        V<int> score(26);
        rep(i,0,n) cin >> c[i];
        bool tie = 1;
        rep(i,0,n) {
            int person = c[i] - 'A';
            score[person]++;
            int left = n-i-1;
            V<pair<int,int>> tmp(26);
            rep(j,0,26) tmp[j] = {score[j],j};
            sort(tmp.rbegin(), tmp.rend());
            if (tmp[0].first - tmp[1].first > left) {
                cout << (char)(tmp[0].second + 'A') << " " << i+1 << endl;
                tie = 0;
                break;
            }
        }
        if (tie) cout << "TIE" << endl;
    }
    
    return 0;
}