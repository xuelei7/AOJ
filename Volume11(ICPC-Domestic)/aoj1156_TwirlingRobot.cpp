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

V<int> c(5);

// up, right, down, left
int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};

struct robot {
    int h, w, dir, cost;
    robot(int h, int w, int dir, int cost) : h(h), w(w), dir(dir), cost(cost) {}
    bool operator < (const robot& other) const {
        return cost < other.cost;
    }
    bool operator > (const robot& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int w,h;
    while (cin >> w >> h, h) {
        VV<int> maze(h, V<int>(w));
        rep(i,0,h) {
            rep(j,0,w) {
                cin >> maze[i][j];
            }
        }
        rep(i,0,4) cin >> c[i];

        VV<V<bool>> used(h, VV<bool>(w, V<bool>(5)));
        priority_queue<robot,vector<robot>,greater<robot>> pq;
        pq.push(robot(0,0,1,0));
        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            robot tmp = tp;
            // cout << tp.h << " " << tp.w << " " << tp.dir << " " << tp.cost << endl;
            if (used[tp.h][tp.w][tp.dir]) continue;
            used[tp.h][tp.w][tp.dir] = 1;
            
            if (tp.h == h-1 && tp.w == w-1) {
                cout << tp.cost << endl;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nxt_dir = (tp.dir + i) % 4;
                int cost = (maze[tp.h][tp.w] != i) * c[i];
                tmp = tp;
                tmp.h += dh[nxt_dir];
                tmp.w += dw[nxt_dir];
                tmp.dir = nxt_dir;
                tmp.cost += cost;
                if (tmp.h < 0 || tmp.h >= h || tmp.w < 0 || tmp.w >= w) continue;
                if (used[tmp.h][tmp.w][tmp.dir]) continue;
                pq.push(tmp);
            }
        }
    }
    
    return 0;
}