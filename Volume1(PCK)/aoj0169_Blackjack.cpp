// ブラックジャック
// ブラックジャックはカジノで行われるカードゲームの一種で、1 〜 13 までの数が書かれたカードを使ってゲームが行われます。各カードの点数は次のように決まっています。

// 1 は 1 点あるいは 11 点
// 2 から 9 までは、書かれている数の通りの点数
// 10 から 13 までは、10 点
// このゲームには親を含めた何人かの参加者がおり、それぞれが何枚かのカードの組を持っています。このカードの組のことを手と呼びます。手の点数はカードの点数の合計です。その計算は次のように行うものとします。

// カードの点数の合計が 21 より大きくなるときは、手の点数を 0 点とする
// カードの点数として、1 は 1 点と計算しても 11 点と計算してもよいが、手の点数が最大となる方を選ぶこととする
// 配られたカードの情報を入力とし、手の点数を出力するプログラムを作成してください。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// c1 c2 ... cn
// １行に i 番目のカードに書かれている整数 ci (1 ≤ ci ≤ 13) が空白区切りで１行に与えられます。カードの数 n は 100 を超えません。

// データセットの数は 200 を超えません。

// Output
// データセットごとに手の点数を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin,s)) {
        if (s == "0") break;
        stringstream ss(s);
        int k;
        int sum = 0;
        int cnt1 = 0;
        while (ss >> k) {
            if (k == 1) cnt1++;
            else if (k >= 10) sum += 10;
            else sum += k;
        }
        sum += cnt1;
        while (cnt1 > 0 && sum + 10 <= 21) {
            sum += 10;
            cnt1--;
        }
        if (sum > 21) sum = 0;
        cout << sum << endl;
    }
    return 0;
}