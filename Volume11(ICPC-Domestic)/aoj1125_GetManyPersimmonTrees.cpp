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
        int w,h;
        cin >> w >> h;
        VV<int> maze(h+1, V<int>(w+1));
        for (int i = 0; i < n; i++) {
            int x,y;
            cin >> x >> y;
            maze[y][x] = 1;
        }
        int s,t;
        cin >> s >> t;
        swap(s,t);
        for (int i = 0; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                maze[i][j] += maze[i][j-1];
            }
        }
        for (int j = 0; j <= w; j++) {
            for (int i = 1; i <= h; i++) {
                maze[i][j] += maze[i-1][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (i >= s && j >= t) {
                    int area = maze[i][j] - maze[i-s][j] - maze[i][j-t] + maze[i-s][j-t];
                    ans = max(ans, area);
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}