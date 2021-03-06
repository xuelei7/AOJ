// 列車
// 26 両以下の編成の列車があります。それぞれの車両には、英小文字の a から z までの識別記号が付いています。同じ記号が付いている車両はありません。ただし、車両を連結する順番は自由とします。列車の中を車掌が巡回します。車掌は、列車の中を行ったり来たりして巡回するので、同じ車両を何度も通ることがあります。ただし、すべての車両を最低一回は巡回するものとします。また、巡回をはじめる車両や巡回を終える車両が列車の一番端の車両とは限りません。

// ある車掌が乗ったすべての列車の巡回記録があります。そこから分かる各列車の編成を先頭車両から出力するプログラムを作成してください。巡回記録は 1 行が 1 つの列車に対応します。各行は、英小文字を 1 文字ずつ <- または -> で区切った文字列でできています。<- は前方の車両への移動、-> は後方の車両への移動を表します。

// 例えば、a->b<-a<-c は車両 a から後方の車両である b に移り、b から前方の a に移り、a から前方の c へ移ったことを表します。この場合の列車の編成は先頭車両から cab となります。

// Input
// １行目に巡回記録の個数 n (n ≤ 50)、続く n 行に巡回記録 i を表す文字列 si (1024文字までの半角文字列) が与えられます。

// Output
// 巡回記録 i について、先頭車両からの列車の編成を表す文字列を i 行目に出力してください。

#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    char ans[100] = {};
    int p = 50;
    ans[p] = s[0];
    for (int i = 1; i < s.size(); i+=3) {
        int d;
        if (s[i] == '-') d = 1;
        else d = -1;
        p += d;
        ans[p] = s[i+2];
    }
    for (int i = 0; i < 100; i++) {
        if (ans[i] >= 'a' && ans[i] <= 'z') {
            cout << ans[i];
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}