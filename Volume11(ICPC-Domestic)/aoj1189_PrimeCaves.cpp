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

vector<bool> getPrimeList() {
    const int MAXN = 2000000;
    vector<bool> isprime(MAXN);
    for (int i = 2; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    return isprime;
}

VV<int> N(2000, V<int>(2000));
vector<pair<int,int>> pos(1010000);
auto isPrime = getPrimeList();

struct node {
    int h, w;
    int prime_n, last_prime;
    node(int h, int w, int n, int l) : h(h), w(w), prime_n(n), last_prime(l) {}
};

void chmax(pair<int,int>& a, pair<int,int> b) {
    if (b.first > a.first) a = b;
    else if (b.first == a.first) a.second = max(a.second, b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int sh = 1000, sw = 1000, num = 1;
    N[sh][sw] = num;
    pos[num] = {sh,sw};

    int dh[4] = {-1,0,1,0};
    int dw[4] = {0,1,0,-1};
    int dir = 2;
    int len = 1;
    while (num <= 1000000) {
        rep(k,0,2) {
            dir = (dir + 3) % 4;
            rep(i,0,len) {
                sh += dh[dir];
                sw += dw[dir];
                N[sh][sw] = ++num;
                if (num <= 1e6)
                    pos[num] = {sh,sw};
            }
        }
        len++;
    }

    int n,m;
    while (cin >> m >> n, m) {
        queue<node> q;
        sh = pos[n].first;
        sw = pos[n].second;
        pair<int,int> ans = {0,0};

        VV<pair<int,int>> dp(2001,V<pair<int,int>>(2001,{-1,-1}));
        VV<bool> used(2000,V<bool>(2000));
        dp[sh][sw] = {isPrime[n],(isPrime[n]?n:0)};
        q.push(node(sh,sw,isPrime[n],(isPrime[n]?n:0)));
        chmax(ans, dp[sh][sw]);
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            int hh = tp.h;
            int ww = tp.w;
            if (used[hh][ww]) continue;
            if (N[hh][ww] == 0 || N[hh][ww] > m) continue;
            used[hh][ww] = 1;
            rep(i,-1,2) {
                int th = hh+1;
                int tw = ww+i;
                num = N[th][tw];
                if (num > m || num == 0) continue;
                int pn = dp[hh][ww].first + isPrime[num];
                int lp = (isPrime[num]? num : dp[th][tw].second);
                chmax(dp[th][tw], {pn, lp});
                chmax(ans, {pn, lp});
                q.push(node(th,tw,pn,lp));
            }
        }

        cout << ans.first << " " << ans.second << endl;
    }
    
    return 0;
}