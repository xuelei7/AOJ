// 平面上の図形
// 縦 8、横 8 のマスからなる図 1 のような平面があります。
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□

// 図１

// この平面上に、以下の A から G の図形のどれかが一つだけ置かれています。

// A
// ■	■		
// ■	■		
// B
// ■		
// ■		
// ■		
// ■		
// C
// ■	■	■	■

// D
//      ■		
// ■	■		
// ■			
// E
// ■	■		
//      ■    ■
// F
// ■			
// ■	■		
//      ■		
// G
//      ■    ■	
// ■	■		

// たとえば、次の図 2 の例では E の図形が置かれています。
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	■	■	□	□	□	□	□
// □	□	■	■	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□

// 図２

// 平面の中で図形が占めているマスを 1、占めていないマスを 0 で表現した数字の列を読み込んで、置かれている図形の種類（A〜G）を出力するプログラムを作成してください。

// ただし、ひとつの平面に置かれている図形は必ず１つで、複数の図形が置かれていることはありません。また、A〜G で表される図形以外のものが置かれていることはありません。

// Input
// 入力は複数のデータセットからなります。

// １つのデータセットとして、平面の中で図形が占めているマスを 1、占めていないマスを 0 で表現した 8 文字からなる 8 つの文字列が与えられます。例えば、図 2 に対応する文字列の並びは次のようになります。

// 0	0	0	0	0	0	0	0
// 0	0	0	0	0	0	0	0
// 0	1	1	0	0	0	0	0
// 0	0	1	1	0	0	0	0
// 0	0	0	0	0	0	0	0
// 0	0	0	0	0	0	0	0
// 0	0	0	0	0	0	0	0
// 0	0	0	0	0	0	0	0

// データセットの間は１つの空行で区切られています。データセットの数は 50 を超えません。

// Output
// 各データセットごとに、平面に与えられた図形の種類（A〜G のいずれか）を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int dx[7][3] = {{1,0,1},{0,0,0},{1,2,3},{0,-1,-1},{1,1,2},{0,1,1},{1,-1,0}};
    int dy[7][3] = {{0,1,1},{1,2,3},{0,0,0},{1,1,2},{0,1,1},{1,1,2},{0,1,1}};
    string s[8];
    while (cin >> s[0]) {
        int ans = -1;
        for (int i = 1; i < 8; i++) cin >> s[i];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (s[i][j] == '1') {
                    for (int k = 0; k < 7; k++) {
                        bool f = 1;
                        for (int t = 0; t < 3; t++) {
                            int ti = i + dy[k][t];
                            int tj = j + dx[k][t];
                            if (ti < 0 || ti >= 8 || tj < 0 || tj >= 8) {
                                f = 0;
                                break;
                            }
                            if (s[ti][tj] != '1') {
                                f = 0;
                                break;
                            }
                        }
                        if (f) {
                            ans = k;
                            break;
                        }
                    }
                    if (ans != -1) break;
                }
            }
            if (ans != -1) break;
        }
        cout << (char)('A' + ans) << endl;
    }
    return 0;
}