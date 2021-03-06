// 問題 B : Evacuation Route
// 問題文
// 日本では防災研究が盛んに行われており，近年その重要性がますます増している． 避難経路の評価も重要な研究のひとつである． 今回は直線状の通路の安全評価を行う．

// 通路は W 個のユニットに分けられており，一方の端のユニットからもう一方の端のユニットまで 0, 1, 2, … , W−1 の番号がつけられている． 通路内の各ユニットには，入口の扉，出口の扉，防火扉のいずれか1つが存在する． 入り口の扉，出口の扉，防火扉はそれぞれ通路内に複数個存在しうる．

// この問題では時刻 t=0 で火災が発生したと想定する． それにより，通路の外部にいて避難しようとしている人々が入口の扉を通じて通路へ入り，より安全な場所へ出るために出口の扉へ脱出しようとするものとする． 避難中のそれぞれの人は単位時刻ごとに 1 つのユニットを移動するか，今のユニットに留まることができる． すなわち，時刻 t にある人がユニット i にいたとするとき，その人は時刻 t+1 ではユニット i−1, i, i+1 の3つの数字のうち 0 以上 W−1 以下であるものを選択し，その番号のユニットへ移動することができる． 防火扉があるユニットは，ある一定時刻以降になると完全に遮断されてしまい，避難中の人々はそのユニットに立ち入りできなくなる．また，そのユニット内に居た人々もそこから他のユニットに移動できなくなってしまう．

// この問題における目的は，それぞれの扉の情報が与えられるので，避難中の人々が最適に行動した時に最大で何人が出口の扉へたどり着けるか計算することである．

// 通路の情報がW個の整数aiで与えられる．

// ai=0のとき，i 番目のユニットが出口の扉であることをあらわす．
// ai<0のとき，i 番目のユニットが防火扉により時間 |ai| 以降出入りできなくなることを表す．
// ai>0のとき，時刻 t=0, 1, 2, … , ai−1 のそれぞれにおいて，ちょうど一人の人が i 番目のユニットに現れる．時刻 t に現れた人は，時刻 t+1 以降から移動を開始する．
// なお，1つのユニットに複数の人々が存在してもかまわない．

// 出口の扉へたどり着ける最大の人数を求めよ．

// 入力形式
// 入力は以下の形式で与えられる

// W
// a0 a1 … aW−1
// 出力形式
// 最大人数を1行で出力せよ．

// 制約
// 1≤W≤105
// |ai| ≤104
// 入力値はすべて整数である．

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

auto solve (int w, V<int>& a) -> int {
    // 時間制限を計算する
    V<int> limit(w,0);
    int inf = 1e9;
    int lim = 0;

    rep(i,0,w) {
        if (a[i] == 0) {
            lim = inf;
        } else if (a[i] < 0) {
            lim = min(lim, -a[i]);
        }
        limit[i] = max(lim, limit[i]);
        lim = max(0, lim - 1);
    }

    lim = 0;
    rrep(i,0,w) {
        if (a[i] == 0) {
            lim = inf;
        } else if (a[i] < 0) {
            lim = min(lim, -a[i]);
        }
        limit[i] = max(lim, limit[i]);
        lim = max(0, lim - 1);
    }

    // 制限よりはやくいれば出られる
    int ret = 0;
    rep(i,0,w) {
        if (a[i] > 0) ret += min(a[i],limit[i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int w;
    cin >> w;
    V<int> a(w);
    rep(i,0,w) cin >> a[i];

    // solve
    auto ans = solve(w,a);

    // output
    cout << ans << endl;
    
    return 0;
}