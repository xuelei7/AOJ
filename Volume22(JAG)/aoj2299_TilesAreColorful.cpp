// J: Tiles are Colorful
// ICPC で良い成績を収めるには修行が欠かせない．うさぎは ICPC で勝ちたいので，今日も修行をすることにした．

// 今日の修行は，流行りのパズルをすばやく解いて，瞬発力を鍛えようというものである．今日挑戦するのは，色とりどりのタイルが並んでいてそれらを上手く消していくパズルだ

// 初期状態では，グリッド上のいくつかのマスにタイルが置かれている．各タイルには色がついている．プレイヤーはゲーム開始後，以下の手順で示される操作を何回も行うことができる．

// タイルが置かれていないマスを 1 つ選択し，そのマスを叩く．
// 叩いたマスから上に順に辿っていき，タイルが置かれているマスに至ったところでそのタイルに着目する．タイルが置かれているマスがないまま盤面の端に辿り着いたら何にも着目しない．
// 同様の操作を叩いたマスから下・左・右方向に対して行う．最大 4 枚のタイルが着目されることになる．
// 着目したタイルの中で同じ色のものがあれば，それらのタイルを盤面から取り除く．同じ色のタイルの組が 2 組あれば，それら両方を取り除く．
// タイルを取り除いた枚数と同じ値の得点が入る．
// 着目をやめる．
// たとえば，以下のような状況を考えよう．タイルが置かれていないマスはピリオドで，タイルの色はアルファベット大文字で表されている．

// ..A.......
// .......B..
// ..........
// ..B.......
// ..A.CC....
// ここで上から 2 行目，左から 3 列目のマスを叩く操作を考える．着目することになるタイルは A , B , B の 3 枚であるから，B の 2 枚が消えて盤面は以下のようになり，2 点を得る．

// ..A.......
// ..........
// ..........
// ..........
// ..A.CC....
// このパズルはゆっくりしていると時間切れになってしまい，盤面の一部が見えなくなりどのくらい修行が足りなかったのかがわからなくなってしまう． 各色のタイルは 2 枚ずつ置かれているが，それらをすべて消せるとは限らないので，予めプログラムに得点の最大値を計算させておきたい．

// Input
// M N
// C1,1C1,2...C1,N
// C2,1C2,2...C2,N
//  ...
// CM,1CM,2...CM,N
// 整数 M, N は盤が 縦 M × 横 N のマス目であることを表す．Ci, j はアルファベット大文字またはピリオド ( . ) であり，上から i 行目，左から j 列目のマスについて，アルファベット大文字の場合は置かれているタイルの色を表し，ピリオドの場合はこのマスにタイルが置かれていないことを表す．

// 1 ≤ M ≤ 500，1 ≤ N ≤ 500 を満たす．各アルファベット大文字は入力中に 0 個または 2 個現れる．

// Output
// 得点の最大値を 1 行に出力せよ．


#include <bits/stdc++.h>
using namespace std;
char maze[510][510];
int hh[2][26], ww[2][26];
int dh[4] = {0,0,-1,1};
int dw[4] = {1,-1,0,0};
int h,w;
int ans;
bool ok (int H, int W, int i) {
    if (maze[H][W] != '.') return 0;
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int th = H + dh[k];
        int tw = W + dw[k];
        while (th >= 0 && th < h && tw >= 0 && tw < w && maze[th][tw] == '.') {
            th += dh[k];
            tw += dw[k];
        }
        if (th >= 0 && th < h && tw >= 0 && tw < w && maze[th][tw] - 'A' == i) cnt++;
    }
    return cnt == 2;
}
void erase(int i) {
    maze[hh[0][i]][ww[0][i]] = maze[hh[1][i]][ww[1][i]] = '.';
    hh[0][i] = hh[1][i] = ww[0][i] = ww[1][i] = -1;
    ans += 2;
}
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> maze[i];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 26; j++) {
            hh[i][j] = ww[i][j] = -1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] != '.') {
                for (int k = 0; k < 2; k++) {
                    if (hh[k][maze[i][j] - 'A'] != -1) continue;
                    hh[k][maze[i][j] - 'A'] = i;
                    ww[k][maze[i][j] - 'A'] = j;
                    break;
                }
            }
        }
    }
    for (int count = 0; count < 26; count++) {
        for (int i = 0; i < 26; i++) {
            if (hh[0][i] == -1) continue;

            // same col
            if (ww[0][i] == ww[1][i]) {
                bool flg = 1;
                int f = hh[0][i];
                int t = hh[1][i];
                if (f > t) swap(f,t);
                if (t - f <= 1) flg = 0;
                for (int j = f + 1; j < t; j++) {
                    if (maze[j][ww[0][i]] != '.')
                        flg = 0;
                }
                if (flg) erase(i);
                continue;
            }
            
            // same row
            if (hh[0][i] == hh[1][i]) {
                bool flg = 1;
                int f = ww[0][i];
                int t = ww[1][i];
                if (f > t) swap(f,t);
                if (t - f <= 1) flg = 0;
                for (int j = f + 1; j < t; j++) {
                    if (maze[hh[0][i]][j] != '.')
                        flg = 0;
                }
                if (flg) erase(i);
                continue;
            }

            // different col and row
            int h1 = hh[0][i];
            int h2 = hh[1][i];
            int w1 = ww[0][i];
            int w2 = ww[1][i];
            swap(h1,h2);
            if (ok(h1,w1,i)) {
                erase(i);
                continue;
            }
            if (ok(h2,w2,i)) {
                erase(i);
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
