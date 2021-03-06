// Problem C: Brave Princess Revisited
// ある貧乏な国のおてんばで勇敢なお姫様が，政略結婚のため別の国に嫁ぐことになった．ところがお姫様を亡き者としようとしている悪漢が嫁ぎ先への道の途中で刺客を放っている．

// お姫様を無事に相手国に送り届けるため，あなたは安全な経路を既に決定していたのだが，お姫様の今までに通ったことのない道を通ってみたいというわがままなたっての願いで別の道を通ることとなった．そこであなたは地図を見ながらお姫様が通る道を決めなおすことにした．

// 全ての道は，宿場同士をつなぐ街道である．便宜上，出発地点及び目的地点も宿場とする．ところが，新しい道は治安の問題を抱えていた．盗賊やお姫様を亡き者にしようとする刺客が襲いかかってくる可能性が高いのである．

// そのような危険な道を通るには護衛を雇うことが望ましい．護衛は宿場で雇うことができ，道単位で姫を守らせることができる．護衛が守っている間は盗賊や刺客に襲われることはないが，距離 1 につき金 1 がかかる．そのため，護衛を雇うためには所持金よりも次の宿場までの距離が長くないことが条件となる．

// いま，与えられた予算 L のもとで，姫が無事に目的地に着くまでに襲いかかってくる盗賊や刺客の人数を最小化することを考える．あなたの仕事は，その最小化された人数を求めることである．なお，宿場にいる間に襲われることはないものとする．

// Input
// 入力は複数のデータセットからなる．各データセットは次の形式をしている．

// N M L
// A1 B1 D1 E1
// A2 B2 D2 E2
// ...
// AM BM DM EM
// 最初の行には 3 つの非負の整数 N (2 ≤ N ≤ 100)，M， L (0 ≤ L ≤ 100) が与えられる．これらの整数は，宿場の数，道の数，護衛を雇うための予算を表す．宿場には 1 から N までの番号が割り振られており，出発地には 1 ，目的地には N の番号がそれぞれ割り振られている．

// 続く M 行では道の情報が各行に 1 つずつ与えられる．道の情報は 4 つの整数 Ai，Bi (1 ≤ Ai < Bi ≤ N)， Di (1 ≤ Di ≤ 100) Ei (0 ≤ Ei ≤ 10000) で与えられる．これらはそれぞれ，道の始点と終点の宿場の番号，道の距離，盗賊や刺客に襲われる人数を表す．

// 道は双方向に通行可能であり，かつある宿場の組に対しては高々 1 つの道しか存在しない．また，出発地から目的地には必ず移動可能であることが保証されている．

// 入力の終わりは，空白で区切られた 3 つの 0 を含む 1 行で示される．

// Output
// 各データセットについて，盗賊や刺客に襲われる人数の最小値を各行に出力せよ．出力に余計な空白や改行を含めてはならない．

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

struct edge {
    int to, cost, enemy;
    edge(int to = 0, int cost = 0, int enemy = 0) : to(to), cost(cost), enemy(enemy) {}
};

auto solve (int n, int m, int l, VV<edge>& G) -> int {
    struct S{
        int enemy, left, id;
        S(int enemy = 0, int left = 0, int id = 0) : enemy(enemy), left(left), id(id) {}
        bool operator >(const S& other) const {
            if (enemy != other.enemy) return enemy > other.enemy;
            if (left != other.left) return left > other.left;
            return id > other.id;
        }
    };
    
    priority_queue<S,vector<S>,greater<S>> pq;
    pq.push(S(0,l,0));

    int inf = 1e9;
    VV<int> dp(n,V<int>(l+1,inf));
    dp[0][0] = 0;
    
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();

        if (dp[tp.id][tp.left] < tp.enemy) continue;

        rep(i,0,G[tp.id].size()) {
            auto e = G[tp.id][i];

            // 払う場合
            if (tp.left >= e.cost && dp[e.to][tp.left - e.cost] > tp.enemy) {
                dp[e.to][tp.left - e.cost] = tp.enemy;
                pq.push(S(dp[e.to][tp.left-e.cost], tp.left-e.cost, e.to));
            }
            // 払わない場合
            if (dp[e.to][tp.left] > tp.enemy + e.enemy) {
                dp[e.to][tp.left] = tp.enemy + e.enemy;
                pq.push(S(dp[e.to][tp.left], tp.left, e.to));
            }
        }
    }

    int mi = inf;
    rep(i,0,l+1) {
        mi = min(mi, dp[n-1][i]);
    }
    if (mi == inf) return -1;
    else return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n,m,l;
    while (cin >> n >> m >> l) {
        if (n+m+l == 0) break; 
        VV<edge> G(n);
        rep(i,0,m) {
            int a,b,d,e;
            cin >> a >> b >> d >> e;
            a--; b--;
            G[a].push_back(edge(b,d,e));
            G[b].push_back(edge(a,d,e));
        }

        // solve
        auto ans = solve(n,m,l,G);

        // output
        cout << ans << endl;
    }
    return 0;
}