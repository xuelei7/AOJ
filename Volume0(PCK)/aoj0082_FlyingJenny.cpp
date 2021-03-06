// メリーゴーランド


// 遊園地にあるメリーゴーランドはご存じでしょう。大きな円盤の上に馬や馬車などの乗り物が固定されていて、円盤が回転すると同時に乗り物が上下に揺れる、定番の遊具です。ある遊園地のメリーゴーランドは、４人乗りの馬車が２台、２人乗りの車２台、１人乗りの馬が４台、計８台の乗り物が図１のような順序で備えられています。そして、遊園地においでのお客様は、図１に示す乗り場０〜７のどこかで待つようになっています。



// この遊園地のメリーゴーランドは、かならず乗り物が乗り場にぴったりと合う位置に停止します。そして、０〜７のそれぞれで待っているお客さまは、目の前にとまった乗り物に乗ることになっています。急いで他の乗り場へ移動してそこから乗るということはできません。効率よく、お客さまにたのしんでいただくためには、メリーゴーランドの停止する位置をうまく調整して、乗れないお客さまをできるだけ少なくするようにしなければなりません。

// 乗り場０〜７で待っているお客さまの人数を読み込んで、どの位置にどの乗り物が来るように止めれば乗れないお客さまが最も少なくなるかを出力するプログラムを作成してください。
// 入力
// 入力は複数のデータセットからなります。各データセットは以下の形式で与えられます。

// p0 p1 p2 p3 p4 p5 p6 p7
// 乗り場 0, 1, ..., 7 で待っているお客様の人数を表す整数 p0, p1,... , p7 ( 0 ≤ pi ≤ 10,000) が空白区切りで１行に与えられます。

// 出力
// メリーゴーランドの乗り物の馬車を 4、車を 2、馬を 1 で表すこととします。乗り場 0, 1, ... , 7 にとめる乗り物を、それぞれ c0, c1,..., c7 とします。データセットごとに、c0, c1,..., c7 を空白区切りで 1 行に出力します。

// なお、乗れなくなるお客さまが最小となるとめ方が複数ある場合は、c0c1c2c3c4c5c6c7 を 8 桁の整数 V とみなし、V が最小となるとめ方を選ぶものとします。

// データセットの数は 100 を超えません。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin,s)) {
        stringstream ss(s);
        int a[8];
        int b[8] = {1,2,1,2,1,4,1,4};
        int go = 0;
        int idx = 0;
        string ans = "";
        for (int i = 0; i < 8; i++) ss >> a[i];
        for (int i = 0; i < 8; i++) {
            int sum = 0;
            for (int j = 0; j < 8; j++) {
                sum += min(a[j],b[(i+j)%8]);
            }
            if (sum > go) {
                go = sum;
                idx = i;
                ans = "";
                for (int j = 0; j < 8; j++) {
                    ans = ans + (char)('0' + b[(i+j)%8]);
                }
            } else if (sum == go) {
                string tmp = "";
                for (int j = 0; j < 8; j++) {
                    tmp = tmp + (char)('0' + b[(i+j)%8]);
                }
                ans = min(ans,tmp);
            }
        }
        for (int i = 0; i < 8; i++) {
            cout << ans[i] << " \n"[i == 7];
        }
    }
    return 0;
}