// 正方形探索
// 縦に n 行、横に n 列並べられた、合計 n×n のマス目があります。いくつかのマス目には印がついています。各マス目の印の状態を読み込み、印のついていないマス目だけからなる最大の正方形の辺の長さを出力として表示するプログラムを作成してください。

// たとえば各データセットで以下のようなデータが与えられます。

// 10
// ...*....**
// ..........
// **....**..
// ........*.
// ..*.......
// ..........
// .*........
// ..........
// ....*..***
// .*....*...
// 入力データの一行が、一行のマス目を表現します。入力データの文字列のうち、.（ピリオド）は印のついていないマス目、*（アスタリスク）は印のついているマス目を示しています。

// 上記の例では、下図の 0 で示される正方形が最大となります。

// ...*....**
// ..........
// **....**..
// ...00000*.
// ..*00000..
// ...00000..
// .*.00000..
// ...00000..
// ....*..***
// .*....*...
// よって、5 と出力すれば正解になります。

// なお、すべてのマス目に印がついている場合には、0 を出力してください。

// Input
// 上記形式で複数のデータセットが与えられます。 n が 0 のとき入力の最後とします。n は 1000 以下とします。入力データの文字列には、ピリオド、アスタリスク、改行以外の文字は含まれません。データセットの数は 50 を超えません。

// Output
// 各データセットに対し、最大の正方形の辺の長さ（整数）を１行に出力して下さい。

#include <bits/stdc++.h>
using namespace std;

char maze[1010][1010];
int dp[1010][1010];
int dp_yoko[1010][1010];
int dp_tate[1010][1010];

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < 1010; i++) {
            memset(dp[i],0,sizeof(dp[i]));
            memset(dp_yoko[i],0,sizeof(dp_yoko[i]));
            memset(dp_tate[i],0,sizeof(dp_tate[i]));
        }
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == '.') dp[i][j] = dp_yoko[i][j] = dp_tate[i][j] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == '*') continue;
                if (i > 0) dp_tate[i][j] = dp_tate[i-1][j] + 1;
                if (j > 0) dp_yoko[i][j] = dp_yoko[i][j-1] + 1;
                if (i > 0 && j > 0) dp[i][j] = min({dp[i-1][j-1], dp_tate[i-1][j], dp_yoko[i][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}