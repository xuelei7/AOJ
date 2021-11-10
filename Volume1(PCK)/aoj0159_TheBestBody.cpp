// 理想の体型
// 肥満度を表す指数としてBMI（Body Mass Index）があります。BMIの値は以下の式で計算します。

// BMI = 体重(kg) / (身長(m))2

// BMIの値が標準値に近いほど「理想の体型」と考えられます。そこで、BMIの標準値を 22 とした場合、対象者の情報を入力とし、最も「理想の体型」に近い人の情報を出力するプログラムを作成してください。

// 対象者の数を n とすると、各対象者には重複のないように1 以上 n 以下の整数値の受付番号 p が振られています。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。各データセットは以下の形式で与えられます。

// n
// p1 h1 w1
// p2 h2 w2
// :
// pn hn wn
// １行目に対象者の人数 n (n ≤ 1000)、続く n 行に i 人目の対象者の受付番号 pi (1 ≤ pi ≤ n)、センチメートル単位の身長 hi (1 ≤ hi ≤ 200)、キログラム単位の体重 wi (1 ≤ wi ≤ 200) が与えられます。入力は全て整数で与えられます。

// Output
// データセットごとに「理想の体型」に最も近い人の受付番号（整数）を１行に出力します。最も「理想の体型」に近い人が二人以上いる場合は、受付番号の小さい方を出力することとします。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int id;
        double mi = 10000;
        for (int i = 0; i < n; i++) {
            int p;
            double h,w;
            cin >> p >> h >> w;
            h /= 100;
            double bmi = w/h/h;
            if (abs(bmi - 22.0) < mi) {
                mi = abs(bmi-22.0);
                id = p;
            } else if (abs(bmi - 22.0) == mi) {
                id = min(id,p);
            }
        }
        cout << id << endl;
    }
    return 0;
}