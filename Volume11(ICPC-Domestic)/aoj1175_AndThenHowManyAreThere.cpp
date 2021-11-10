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

struct Circle {
    int x, y, r;
    int c;
    Circle(){}
    Circle(int x, int y, int r, int c) : x(x), y(y), r(r), c(c) {}
};

int square(int x) {
    return x*x;
}

bool intersect(Circle a, Circle b) {
    if (square(a.x-b.x) + square(a.y-b.y) >= square(a.r+b.r)) return false;
    return true;
}

int f(V<Circle>& v, V<int>& dp, int sta) {
    if (dp[sta] != -1) return dp[sta];
    int ret = 0;
    bool not_covered = true;
    rep(i,0,v.size()) {
        if ((sta >> i) & 1) continue; // make sure i not taken
        // i not covered by other pieces
        not_covered = true;
        rep(tmp,0,i) {
            if ((sta>>tmp)&1) continue; // do not count ones that was taken
            if (intersect(v[i], v[tmp])) {
                not_covered = false;
                break;
            }
        }
        if (!not_covered) continue;

        rep(j,i+1,v.size()) {
            if (v[i].c != v[j].c) continue; // make sure i and j are same color
            if ((sta >> j) & 1) continue; // j not taken
            // j not covered by other pieces
            not_covered = true;
            rep(tmp,0,j) {
                if ((sta>>tmp)&1) continue;
                if (intersect(v[j], v[tmp])) {
                    not_covered = false;
                    break;
                }
            }
            if (!not_covered) continue;


            // take i and j and see next step
            // cout << i << " " << j << " " << bitset<8>(sta) << endl;
            ret = max(ret, f(v, dp, sta | (1<<i) | (1<<j)) + 2);
        }
    }
    return dp[sta] = ret;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    int n;
    while (cin >> n,n) {
        V<Circle> v(n);
        V<int> dp(1<<n, -1);
        rep(i,0,n) {
            cin >> v[i].x >> v[i].y >> v[i].r >> v[i].c;
        }

        cout << f(v, dp, 0) << endl;

        // rep(i,0,(1<<n)) {
        //     if (dp[i] == -1) continue;
        //     cout << bitset<6>(i) << " " << dp[i] << endl;
        // }
    }
    
    return 0;
}