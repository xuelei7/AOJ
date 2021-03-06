// ヨセフのおイモ


// 昔、ヨセフのおイモというゲームがありました。n 人が参加しているとしましょう。参加者は中心を向いて円陣を組み、1 から順番に番号が振られます。アツアツのおイモがひとつ、参加者 n (左の図内側の大きい数字の 30 )に渡されます。おイモを渡された参加者は右隣の参加者にそのおイモを渡します。 m 回目に渡された人は右隣の人に渡して円陣から抜けます(左の図では m = 9 の場合を表しています) 。 回渡す毎に一人ずつぬけ、最後に残った人が勝者となり、おイモをいただきます。

// n ,m が決まってから、実際におイモを渡し始める前にどこにいたら勝てるかわかるといいですよね。上の図は 30 人の参加者で 9 人ごとに抜けるというルールでこのゲームをした場合を書き表しています。内側の大きい数字が参加者に振られた番号、外側の小さい数字が抜ける順番です。それによると、9,18,27,6,16,26 という順番で円陣から抜け出し、最後には 21 が残ることになります。すなわち 21 が勝者となります(小さい数字が 30 になっています)。

// ゲーム参加者数 n と円陣から抜け出す参加者の間隔 m を入力し、勝者の番号を出力するプログラムを作成してください。ただし、m, n < 1000 とします。

// 入力
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// n m
// ゲーム参加者数 n （整数）と円陣から抜け出す参加者の間隔 m （整数）が空白区切りで１行に与えられます。

// 入力は２つの 0 で終わります。データセットの数は 50 を超えません。

// 出力
// 各データセットに対して、勝者となりおイモをいただく人の番号（整数）を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        if (m == 0 || m == 1) {
            cout << n << endl;
            continue;
        }
        bool decided[1010] = {};
        int now = m-1;
        decided[now] = 1;
        for (int round = 0; round < n-1; round++) {
            vector<int> v;
            for (int i = 0; i < n; i++)
                if (!decided[(now+i)%n]) v.push_back((now+i)%n);
            now = v[(m-1)%v.size()];
            decided[now] = 1;
        }
        cout << now + 1 << endl;
    }
    return 0;
}