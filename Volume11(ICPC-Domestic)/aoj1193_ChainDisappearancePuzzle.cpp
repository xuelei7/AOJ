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

void print(VV<int>& v) {
    cout << "------------" << endl;
    for (auto e: v) {
        for (auto ee: e)
            cout << ee << " ";
        cout << endl;
    }
    cout << "------------" << endl;
}

int myclear(VV<int>& v) {
    int ret = 0;
    for (auto& e: v) {
        for (int i = 0; i < 3; i++) {
            // count
            int fwd = i;
            while (fwd < 5 && e[fwd] == e[i]) fwd++;
            if (fwd - i >= 3) {
                ret += (fwd - i) * e[i];
                // clear
                for (int j = i; j < fwd; j++) e[j] = 0;
                break;
            }
        }
    }
    return ret;
}

void fall(VV<int>& v) {
    for (int col = 0; col < 5; col++) {
        V<int> tmp;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i][col] != 0) tmp.push_back(v[i][col]);
        }
        while (tmp.size() < v.size()) tmp.push_back(0);
        reverse(all(tmp));
        for (int i = 0; i < v.size(); i++) {
            v[i][col] = tmp[i];
        }
    }
}

int f(VV<int>& v) {
    int ret = myclear(v);
    // print(v);
    fall(v);
    // print(v);
    // cout << ret << endl;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int r;
    while (cin >> r, r) {
        VV<int> v(r, V<int>(5));
        rep(i,0,r) rep(j,0,5) cin >> v[i][j];
        int score = 0;
        while(1) {
            int s = f(v);
            if (s == 0) break;
            score += s;
        }
        cout << score << endl;
    }
    
    return 0;
}