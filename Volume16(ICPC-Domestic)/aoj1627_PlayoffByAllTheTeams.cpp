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

int n,m;

int f(int team, int against, VV<int>& table, V<int>& win, V<int>& lost) {
    // end game
    if (team == n) {
        // cout << "ok" << endl;
        return 1;
    }
    
    // end team
    if (against == n) {
        if (win[team] != lost[team]) return 0;
        return f(team+1, 0, table, win, lost);
    }

    // cout << team << " " << against << " " << table[team][against] << endl;
    // rep(i,0,n) {
    //     rep(j,0,n) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "win:  ";
    // rep(i,0,n) cout << win[i] << " ";
    // cout << endl;
    // cout << "lost: ";
    // rep(i,0,n) cout << lost[i] << " ";
    // cout << endl; 
    // cout << "------------" << endl;
    // self game
    if (team == against) return f(team, against+1, table, win, lost);
    
    int ret = 0;
    // win game
    if (table[team][against] == 1) {
        if (win[team]+1 > n/2) return 0;
        win[team]++;
        ret = f(team, against+1, table, win, lost);
        win[team]--;
        return ret;
    }
    // lost game
    if (table[team][against] == -1) {
        if (lost[team]+1 > n/2) return 0;
        lost[team]++;
        ret = f(team, against+1, table, win, lost);
        lost[team]--;
        return ret;
    }

    // if win
    {
        table[team][against] = 1;
        table[against][team] = -1;
        win[team]++;
        // lost[against]++;

        if (win[team] <= n/2)
            ret += f(team, against+1, table, win, lost);

        table[team][against] = 0;
        table[against][team] = 0;
        win[team]--;
        // lost[against]--;
    }

    // if lost
    {
        table[team][against] = -1;
        table[against][team] = 1;
        // win[against]++;
        lost[team]++;

        if (lost[team] <= n/2)
            ret += f(team, against+1, table, win, lost);

        table[team][against] = 0;
        table[against][team] = 0;
        // win[against]--;
        lost[team]--;
    }

    // cout << team << " " << against << " " << ret << endl;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    while (cin >> n >> m, n) {
        VV<int> table(n, V<int>(n));
        V<int> win(n), lost(n);
        rep(i,0,m) {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            table[a][b] = 1;
            table[b][a] = -1;
        }

        cout << f(0,0,table,win,lost) << endl;
    }
    
    return 0;
}