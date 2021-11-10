// 有料道路通行料
// 20XX年に喜多方市熱塩加納町から南会津町までの6区間、総距離58kmの会津中央道路が完成し開通する予定です。

// 開通後、半年間は利用促進のため17時30分〜19時30分までに出発ICか到着ICを通過し、なおかつ走行距離が40km以下の車に対する通行料金は半額になります。ただし料金は50円単位とし、端数は切り上げます。下記の表は料金と距離の一覧表です。





// 例えば喜多方（２）から会津若松（４）までは料金が450円、距離が12kmとなります。半額時間帯であれば250円になります。

// 出発IC、出発IC通過時刻、到着IC、到着IC通過時刻を入力とし、料金を計算して出力するプログラムを作成してください。ただし、入力される時刻は24 時間表記の値とします。なお、17時30分および19時30分ちょうどに通過した場合も半額時間帯に含めます。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// d
// hd md
// a
// ha ma
// １行目に出発ICの番号 d (1 ≤ d ≤ 7)、２行目に出発ICの通過時刻の時間 hd (0 ≤ hd ≤ 23) と分 md (0 ≤ md ≤ 59) が与えられます。

// 3行目に到着ICの番号 a (1 ≤ a ≤ 7)、４行目に到着ICの通過時刻の時間 ha (0 ≤ ha ≤ 23) と分 ma (0 ≤ ma ≤ 59) が与えられます。

// Output
// データセットごとに通行料金（整数）を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int cost[7][7] = {
    {   0, 300, 500, 600, 700,1350,1650},
    { 300,   0, 350, 450, 600,1150,1500},
    { 500, 350,   0, 250, 400,1000,1350},
    { 600, 450, 250,   0, 250, 850,1300},
    { 700, 600, 400, 250,   0, 600,1150},
    {1350,1150,1000, 850, 600,   0, 500},
    {1650,1500,1350,1300,1150, 500,   0}
};
int len[7][7] = {
    { 0, 6,13,18,23,43,58},
    { 6, 0, 7,12,17,37,52},
    {13, 7, 0, 5,10,30,45},
    {18,12, 5, 0, 5,25,40},
    {23,17,10, 5, 0,20,35},
    {43,37,30,25,20, 0,15},
    {58,52,45,40,35,15, 0}
};

int main() {
    int a,b;
    while (cin >> a) {
        if (a == 0) break;
        int ha,ma,hb,mb;
        cin >> ha >> ma >> b >> hb >> mb;
        a--;
        b--;
        int c = cost[a][b];
        int l = len[a][b];
        int in = 0;
        int t1 = ha * 100 + ma;
        int t2 = hb * 100 + mb;
        bool half = 1;
        half &= ((t1 >= 1730 && t1 <= 1930) || (t2 >= 1730 && t2 <= 1930));
        half &= (l <= 40);
        if (half) {
            c /= 2;
            if (c % 50 != 0) {
                c += 25;
            }
        }
        cout << c << endl;
    }
    return 0;
}