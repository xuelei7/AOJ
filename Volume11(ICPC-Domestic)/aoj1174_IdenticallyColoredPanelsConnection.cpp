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

int h,w,c;
struct Maze {
    int m[10][10];
    bool operator < (const Maze& other) const {
        rep(i,0,h) {
            rep(j,0,w) {
                if (m[i][j] != other.m[i][j]) return m[i][j] < other.m[i][j];
            }
        }
        return false;
    }
    void print() {
        rep(i,0,h) {
            rep(j,0,w) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----------" << endl;
    }
};

int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};


int color(Maze& mz, int nc, int oc, int hh, int ww) {
    // cout << hh << " " << ww << endl;
    int ret = 1;
    mz.m[hh][ww] = nc;
    rep(i,0,4) {
        int th = hh + dh[i];
        int tw = ww + dw[i];
        if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
        if (mz.m[th][tw] != oc) continue;
        ret += color(mz, nc, oc, th, tw);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    while (cin >> h >> w >> c, h) {
        Maze mz;
        rep(i,0,h) {
            rep(j,0,w) {
                cin >> mz.m[i][j];
            }
        }

        int ret = 1;
        set<Maze> st;
        st.insert(mz);
        rep(t,0,6) {
            set<Maze> stt;
            for (auto e: st)
            rep(nc,1,7) {
                if (t == 4 && nc != c) continue;
                if (t == 5 && nc == c) continue;
                if (nc == e.m[0][0]) continue;
                Maze maze = e;
                ret = max(ret, color(maze,nc,maze.m[0][0],0,0));
                stt.insert(maze);
                // cout << t << endl;
                // maze.print();
            }
            st.clear();
            st = stt;
        }
        cout << ret << endl;
    }

    
    return 0;
}