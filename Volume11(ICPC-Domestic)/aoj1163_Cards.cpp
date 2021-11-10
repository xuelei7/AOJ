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

class FordFulkerson{
public:
  struct edge{int to, rev, cap;};

  const int INF = 2e9;
  static const int MAX_V = 10000;

  vector<edge> G[MAX_V];
  bool used[MAX_V] = {};
  void add_edge(int frm, int to, int cap) {
    G[frm].push_back((edge){to, (int)G[to].size(), cap});
    G[to].push_back((edge){frm, (int)G[frm].size() - 1, 0});
  }
  int dfs(int frm, int to, int flow) {
    if (frm == to) return flow;
    used[frm] = 1;
    for (int i = 0; i < G[frm].size(); i++) {
      edge &e = G[frm][i];
      if (!used[e.to] && e.cap > 0) {
        int d = dfs(e.to, to, min(flow, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  int maxflow(int s, int t) {
    int flow = 0;
    while (1) {
      memset(used, 0, sizeof(used));
      int f = dfs(s, t, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int m,n;
    while (cin >> m >> n, m) {
        FordFulkerson mf;
        V<int> b(m);
        V<int> r(n);
        rep(i,0,m) cin >> b[i];
        rep(i,0,n) cin >> r[i];

        rep(i,0,m) mf.add_edge(1001, i+1, 1);
        rep(i,0,n) mf.add_edge(i+501, 1002, 1);
        rep(i,0,m) {
            rep(j,0,n) {
                if (__gcd(b[i], r[j]) != 1) {
                    mf.add_edge(i+1,j+501,mf.INF);
                }
                // cout << b[i] << " " << r[j] << " " << __gcd(b[i], r[j]) << endl;
            }
        }
        cout << mf.maxflow(1001, 1002) << endl;
    }
    
    return 0;
}