// 福縞軒
// 「福縞軒」は行列のできる人気のラーメン屋です。でも最近、お客さんの間から「待ち時間が長いのに、店に入ったら空席があるのは許せない」という声が聞こえるようになってきました。どうしてそんな不満が出るのか調べたいのですが、お店が開いているあいだは忙しくて、実際の行列の様子を調べることができません。しかし、長年の経験からお客さんが来る間隔や人数は分かっているので、それをもとに待ち時間の分析をすることにしました。

// 店内にはカウンターに向かって 17 の席があります。開店時間は正午で、お客さんは次のようにやってきます。

// 0 番から 99 番までの 100 組のグループが来ます。
// i 番目のグループは正午から 5i 分後にお店に到着します。
// i 番目のグループの人数は i % 5 が 1 のとき 5 人、それ以外のときは 2 人です。
// (x % yは x を y で割ったときの余りを表わします。)
// i 番目のグループは、席に着くと 17(i % 2) + 3(i % 3) + 19 分間で食事を済ませます。
// 最初の 10 グループの到着時刻、人数、食事時間は次のようになります。

// グループ番号	0	1	2	3	4	5	6	7	8	9
// 到着時刻(分後)	0	5	10	15	20	25	30	35	40	45
// 人数(人)	2	5	2	2	2	2	5	2	2	2
// 食事時間(分)	19	39	25	36	22	42	19	39	25	36

// また、お客さんを席に案内するときには、次のようにしています。

// 席には 0 から 16 までの番号が付いています。
// x 人のグループは連続して x 個あいている席があった時だけ着席できます。
// また、座れる場所が複数あった場合は、席の番号が最も小さくなるところに座ります。例えば、0、1、2、4、5番の席だけが空いていた場合、5 人のグループは着席できません。2 人のグループであれば 0、1 番に着席します。

// 一度着席したら、席を移動してもらうことはしません。
// お客さんは 1 分単位で出入りします。各時刻には次の順序でお客さんを案内します。
// 前のグループの離席と同時に次のグループの着席が可能となります。
// お客さんを着席させる際には、行列の先頭にいるグループから順に、できる限り多くのグループを同じ時刻に着席させます。行列の順序を追い越すことはしません。つまり、先頭のグループが着席できなければ、行列内の他のグループが着席できたとしても、着席させません。
// その時刻に到着したグループは、行列が残っている場合は行列の最後尾に並びます。行列が無く、着席できる場合は着席し、できない場合は並んで待ちます。例として最初の 10 グループが到着するまでの様子を示すと以下のようになります。各行の3つの欄は、左から時刻、座席の様子、行列の様子を示しています。座席は「_」が空席で、番号はその席にその番号のグループが座っていることを示しています。
// 時刻: 座席                  行列
// 0:    00_______________:
// 5:    0011111__________:
// 10:   001111122________:
// 15:   00111112233______:
// 18:   00111112233______:
// 19:   __111112233______:
// 20:   44111112233______:
// 25:   4411111223355____:
// 30:   4411111223355____:   66666       グループ6が到着
// 34:   4411111223355____:   66666
// 35:   4411111__3355____:   6666677     グループ7が到着
// 40:   4411111__3355____:   666667788   グループ8が到着
// 41:   4411111__3355____:   666667788
// 42:   __11111__3355____:   666667788
// 43:   __11111__3355____:   666667788
// 44:   6666677883355____:               グループ6、7、8が着席
// 45:   666667788335599__:               グループ9が到着、着席
// 例えば、時刻 40 では 8 番目のグループが到着しますが、着席できないので行列に加わります。4 番目のグループは時刻 41 まで食事をします。時刻 42 では、4 番目のグループの席が空きますが、連続した席数が足りないので 6 番目のグループはまだ着席できません。1 番目のグループは時刻 43 まで食事をします。時刻 44 で 1 番目のグループの席が空くので、6 番目のグループが着席し、同時に 7 番目、8 番目のグループも着席します。9 番目のグループは時刻 45 で到着し、席が空いているのでそのまま着席します。

// これらの情報を基にして、0 以上 99 以下の整数 n を入力として、n 番目グループのお客さんが待つ時間(分単位)を出力するプログラムを作成してください。

// Input
// 複数のデータセットが与えられます。各データセットは１つの整数 n からなります。

// データセットの数は 20 を超えません。

// Output
// 各データセットについて、n 番目のお客の分単位の待ち時間(0 以上の整数)を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[17];
    int ans[110];
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    queue<pair<int,int>> q;
    for (int t = 0; t < 10000; t++) {
        for (int i = 0; i < 17; i++) {
            if (a[i] > 0) a[i]--;
        }
        
        if (t % 5 == 0 && t / 5 < 100) {
            int n = t / 5;
            q.push({n, 17*(n%2) + 3*(n%3) + 19});
        }

        while (!q.empty()) {
            pair<int,int> tp = q.front();
            int num = 2;
            if (tp.first % 5 == 1) num = 5;
            bool in = 0;
            for (int i = 0; i + num - 1 < 17; i++) {
                bool f = 1;
                for (int j = 0; j < num; j++) {
                    if (a[i+j] != 0) {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    q.pop();
                    in = 1;
                    for (int j = 0; j < num; j++) {
                        a[i+j] = tp.second;
                    }
                    ans[tp.first] = t - tp.first * 5;
                    break;
                }
            }
            if (!in) break;
        }
        
    }

    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }
    return 0;
}