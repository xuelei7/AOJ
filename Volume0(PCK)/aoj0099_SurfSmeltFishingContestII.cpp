// ワカサギ釣り大会 2
// 桧原湖でワカサギ釣り大会が行われました。今回はキャッチ＆リリースが推奨されているようです。

// 参加者番号と釣った匹数またはリリースした匹数を１つのイベントとして順番に読み込み、各イベントの直後に最も多くのワカサギを手元に獲得している参加者番号と匹数を出力するプログラムを作成してください。最も多く獲得している参加者が複数いる場合（あるいは全ての参加者が 0 匹の場合）は、その中で参加者番号が最も小さい一人を出力してください。

// 入力
// 入力は以下の形式で与えられる。

// n q
// a1 v1
// a2 v2
// : 
// aq vq
// n (1 ≤ n ≤ 1000000) は参加者の数、q (1 ≤ q ≤ 100000)はイベントの数を表す。ai (1 ≤ ai ≤ n)   vi ( -100 ≤ vi ≤ 100) は、i 番目のイベントで参加者 ai が vi 匹獲得あるいはリリースしたことを示す。vi は正の値が獲得、負の値がリリースを示し、0 が与えられることはない。

// 出力
// 各イベントごとに、最も多くのワカサギを手元に獲得している参加者の参加者番号と匹数を１つの空白区切りで１行に出力する。

#include <bits/stdc++.h>
using namespace std;

int cnt[1000010];
int main() {
    int n,q;
    cin >> n >> q;
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < q; i++) {
        int a,b;
        cin >> a >> b;
        cnt[a] += b;
        pq.push({cnt[a],-a});
        while (1) {
            pair<int,int> tp = pq.top();
            if (tp.first != cnt[-tp.second]) {
                pq.pop();
                continue;
            }
            cout << -tp.second << " " << tp.first << endl;
            break;
        }
    }
    return 0;
}