// おはじき取り
// 一郎君と次郎君の兄弟は家でよくおはじき取りをして遊びます。おはじき取りは、一カ所に積まれた複数のおはじきを二人が交互にとっていくゲームです。一度に1〜4個のおはじきを好きな数だけ順に取り、相手に最後の1個を取らせた方が勝ちになります。二人はいつも 32 個のおはじきを使い、兄である一郎君の番からゲームを始めます。

// これまでに何度も戦っている二人ですが、次郎君は兄の一郎君にどうしても勝つことができません。それもそのはず、一郎君はこのゲームの必勝法を知っているからです。一郎君は、残りのおはじきの数を n とすると、必ず (n - 1) % 5 個のおはじきを取ります。ここで x % y は、x を y で割った余りを示します。

// 一方、次郎君は、残りのおはじきの数にかかわらず、ゲームのはじめに各回で取るおはじきの数を数列として決めてしまうのです。例えば、次郎君が決めた数列が{ 3, 1, 4, 2 } であるならば、彼の取るおはじきの数は順に 3 -> 1 -> 4 -> 2 -> 3 -> 1 -> 4 -> … となります（取ると決めた数が、おはじきの残りの数以上になった場合は、残りのおはじき全てを取ります）。

// なんど負けてもやり方を変えようとしない頑固な次郎君の将来が心配になったお母さんは、次郎君がいかなる数列を選んだとしても一郎君には勝てないということを示すために、ゲームをシュミレートするプログラムを書くことにしました。

// 次郎君の考えた数列 a を入力とし、一郎君と次郎君が順次おはじきを取った後の残りのおはじきの個数を出力するプログラムを作成してください。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// n
// a1 a2 ... an
// １行目に次郎君の決めた数列の長さ n (1 ≤ n ≤ 25)、２行目に数列の i 番目の要素 ai (1 ≤ ai ≤ 4) が空白区切りで与えられます。入力はすべて整数で与えられます。

// データセットの数は 100 を超えません。

// Output
// データセットごとに、ゲームの各回でのおはじきが取られた直後のおはじきの数（整数）を出力します。

#include <bits/stdc++.h>
using namespace std;

int a[30];
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> a[i];
        int k = 32, now = 0;
        while (1) {
            k -= (k-1) % 5;
            cout << k << endl;
            if (k == 0) break;
            k = max(0,k-a[now]);
            cout << k << endl;
            if (k == 0) break;
            now++;
            now %= n;
        }

    }
    return 0;
}