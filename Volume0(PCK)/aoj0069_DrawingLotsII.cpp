// あみだくじ II
// 縦線が n 本のあみだくじがあります。このあみだくじは以下の条件を満たしています。

// 横線は真横に引きます。斜めに引くことはありません。
// 横線は必ず隣り合った縦線同士をつなぎます。つまり、横線が縦線をまたぐことはありません。
// どの縦線についても同じ点から左右同時に横線が出ることはありません。つまり、横線が縦線を横切ることはありません。
// 当りはひとつだけです。
// 下図 に n = 5 のときの、あみだくじの例を示します。上側の数字は縦線の番号(左から1, 2, 3, 4, 5 ) を表します。☆が当たりです。



// 縦線の本数 n、選んだ縦線の番号 m、あみだくじの当りの場所、各段における横線の有無を読み込んで、当りにたどり着けるかどうかの判定を出力するプログラムを作成してください。ただし、与えられたあみだくじの任意の位置に1 本だけ横線を付け加えることができるものとします（付け加えなくてもかまいません）。横線を1 本付け加えた後のあみだくじも前述の条件を満たしていなければなりません。

// Input
// 複数のデータセットが与えられます。各データセットは以下のとおりです：

// １行目に、縦線の本数 n (1 < n ≤ 10) が書かれています。
// ２行目には、選んだ縦線の番号 m (1 ≤ m ≤ n) が書かれています。
// ３行目には、当りの場所（図でいう☆）が左から数えて何番目かが書かれています。
// ４行目には、あみだくじの段数 d (1 ≤ d ≤ 30) が書かれています。
// ５行目以降は、図に対応する数字の並びのように、あみだくじの上から順に、各縦線の間に横線があるときを 1、ないときを 0 として、n - 1 つの数字が並んでいます。
// 入力は１つの 0 が書かれた行で終わります。

// Output
// 各データセットについて、選んだ縦線の番号 m から当りにたどり着けるかどうかに応じて以下の値を出力してください。

// 横線を引かなくても当りにたどり着けるときは 0 を出力してください。
// 横線を1 本引けば当りにたどり着けるときは、その中で最も出発側（図でみて上）に近い横線の位置を出力してください。出発側から数えて何段目（図 を参考にしてください）に、左から数えて何番目の縦線から右に向かって横線を引くかを半角の空白で区切って出力してください。
// 横線を1 本引いても当りにたどり着けないときには 1 を出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int m, atari, d;
        cin >> m >> atari >> d;
        int a[11][35];
        for (int i = 1; i <= n; i++) a[0][i] = i;
        string s[35];
        for (int i = 1; i <= d; i++) {
            cin >> s[i];
            for (int j = 1; j <= n; j++) a[i][j] = a[i-1][j];
            for (int j = 0; j < n-1; j++) {
                if (s[i][j] == '1') {
                    swap(a[i][j+1],a[i][j+2]);
                }
            }
        }
        if (a[d][atari] == m) {
            cout << 0 << endl;
            continue;
        }
        int k = a[d][atari];
        bool ok = 0;
        for (int i = 1; i <= d; i++) {
            for (int j = 0; j < n-1; j++) {
                if (s[i][j] == '1') continue;
                if (j-1>=0 && s[i][j-1] == '1') continue;
                if (j+1<n-1 && s[i][j+1] == '1') continue;
                if (a[i][j+1] == m && a[i][j+2] == k) {
                    cout << i << " " << j + 1 << endl;
                    ok = 1;
                    break;
                }
                if (a[i][j+1] == k && a[i][j+2] == m) {
                    cout << i << " " << j + 1 << endl;
                    ok = 1;
                    break;
                }
            }
            if (ok) break;
        }
        if (!ok) cout << 1 << endl;
    }
    return 0;
}