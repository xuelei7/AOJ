// 7 パズル
// 7 パズルは 8 つの正方形のカードとこれらのカードがぴたりと収まる枠で構成されています。それぞれのカードには、互いに区別できるように 0, 1, 2, ..., 7 と番号がつけられています。枠には、縦に 2 個、横に 4 個のカードを並べることができます。

// 7 パズルを始めるときには、まず枠にすべてのカードを入れます。枠のなかで 0 のカードだけは、上下左右に隣接するカードと位置を交換することができます。たとえば、枠の状態が図(a) のときに、0 のカードの右に隣接した、7 のカードと位置を交換すれば、図(b) の状態になります。あるいは、図(a) の状態から 0 のカードの下に隣接した 2 のカードと位置を交換すれば図(c) の状態になります。図(a) の状態で 0 のカードと上下左右に隣接するカードは 7 と 2 のカードだけなので、これ以外の位置の入れ替えは許されません。

// ゲームの目的は、カードをきれいに整列して図(d) の状態にすることです。最初の状態を入力とし、カードをきれいに整列するまでに、必要な最小手数を出力するプログラムを作成してください。ただし、入力されたカードの状態からは図(d) の状態に移ることは可能であるとします。

// 入力データは、1 行に 8 つの数字が空白区切りで与えられます。これらは、最初の状態のカードの並びを表します。例えば、図(a) の数字表現は0 7 3 4 2 5 1 6 に、図(c) は 2 7 3 4 0 5 1 6 となります。

	
// 図(a) 0 7 3 4 2 5 1 6 の場合	図(b) 7 0 3 4 2 5 1 6 の場合


	
// 図(c) 2 7 3 4 0 5 1 6 の場合	図(d) 0 1 2 3 4 5 6 7 (最終状態)

// Input
// 上記形式で複数のパズルが与えられます。入力の最後まで処理してください。 与えられるパズルの数は 1,000 以下です。

// Output
// 各パズルについて、最終状態へ移行する最小手数を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {0,1,2,3,4,5,6,7};
    map<string,int> mp;
    pair<int,int> p[] = {
        {0,1},
        {1,2},
        {2,3},
        {4,5},
        {5,6},
        {6,7},
        {0,4},
        {1,5},
        {2,6},
        {3,7}
    };
    mp["01234567"] = 0;
    queue<pair<string,int>> q;
    q.push({"01234567",0});
    while (!q.empty()) {
        pair<string,int> tp = q.front();
        q.pop();
        string s = tp.first;
        int cnt = tp.second;
        for (int i = 0; i < 10; i++) {
            string ss = s;
            if (ss[p[i].first] == '0' || ss[p[i].second] == '0')
                swap(ss[p[i].first],ss[p[i].second]);
            if (!mp.count(ss)) {
                mp[ss] = cnt+1;
                q.push({ss,cnt+1});
            }
        }
    }
    string s;
    while (getline(cin,s)) {
        string ts = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') ts += s[i];
        }
        cout << mp[ts] << endl;
    }
    return 0;
}