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

struct Point {
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y) {}
    bool operator < (const Point & other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator != (const Point& other) const {
        return x != other.x || y != other.y;
    }
    Point operator - (const Point& other) const {
        return Point(x-other.x,y-other.y);
    }
    void roll() {
        int tx = x;
        int ty = y;
        x = -ty;
        y = tx;
    }
};

void toVec(V<Point>& v) {
    Point pre = v[0];
    rep(i,1,v.size()) {
        Point vec = v[i] - pre;
        pre = v[i];
        v[i] = vec;
    }
}

void roll(V<Point>& v) {
    for (auto& e: v) {
        e.roll();
    }
}

bool same(V<Point>& v1, V<Point>& v2) {
    if (v1.size() != v2.size()) return false;
    rep(i,1,v1.size()) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    int n;
    while (cin >> n, n) {
        VV<Point> v(n+2);
        V<Point> rv;
        rep(i,0,n+1) {
            int m;
            cin >> m;
            rep(j,0,m) {
                int x,y;
                cin >> x >> y;
                v[i].push_back(Point(x,y));
            }
        }

        rep(i,0,v[0].size()) rv.push_back(v[0][i]);
        reverse(all(rv));
        rep(i,0,v[0].size()) v[n+1].push_back(rv[i]);

        rep(i,0,n+2) toVec(v[i]);
        rep(i,0,n+2) {
            while (v[i][1].x != 0 || v[i][1].y < 0) {
                roll(v[i]);
            }
        }

        rep(i,1,n+1) {
            if (same(v[i], v[0])) {
                cout << i << endl;
                continue;
            }
            if (same(v[i], v[n+1])) {
                cout << i << endl;
                continue;
            }
        }
        cout << "+++++" << endl;
    }

    return 0;
}