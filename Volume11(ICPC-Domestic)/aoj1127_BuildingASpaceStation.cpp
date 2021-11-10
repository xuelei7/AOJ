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
    double x,y,z,r;
    Point(){}
    Point(double x, double y, double z, double r): x(x), y(y), z(z), r(r) {}
    bool operator < (const Point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        if (z != other.z) return z < other.z;
        return r < other.r;
    }
    double dist(Point& other) {
        return max(0.0, sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) + (z-other.z)*(z-other.z)) - r - other.r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n, n) {
        set<Point> st;
        rep(i,0,n) {
            double x,y,z,r;
            cin >> x >> y >> z >> r;
            st.insert(Point(x,y,z,r));
        }

        V<Point> v;
        for (auto p: st) {
            v.push_back(p);
        }

        double ret = 0;
        set<int> group;
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        group.insert(0);
        for (int i = 1; i < v.size(); i++) {
            pq.push({v[0].dist(v[i]), i});
        }

        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            if (group.find(tp.second) != group.end()) continue;
            group.insert(tp.second);
            ret += tp.first;
            for (int i = 0; i < v.size(); i++) {
                pq.push({v[tp.second].dist(v[i]), i});
            }
        }

        cout << fixed << setprecision(3) << ret << endl;
    }
    
    return 0;
}