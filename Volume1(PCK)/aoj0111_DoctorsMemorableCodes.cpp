// 博士の暗号
// 博 士 : ?D-C'KOPUA

// ピーター : どうしたんですか、デビッド博士? わけのわからないことを叫ぶのにはもう慣れましたが、 今日は文章にすらなっていませんよ。

// 博 士 : ほれ。



// ピーター : なんですか? この表は......ああ、予選の問題にこんなのがありました。表を使って文字を置き換え ると文字数が減るんですよね。まさか予選と本選で同じ問題を出して手を抜こうって気じゃないでし ょうね。

// 博 士 : 逆じゃよ。

// ピーター : 逆? なるほど、今度は短くした文字列を元に戻そうって問題ですか。ということは「?D-C'KOPUA」の 文字を、この表を使って「文字」から「符号」に置きかえるんですね......できましたよ。

// 11111 00011 11101 00010 11110 01010 01110 01111 10100 00000
// 博 士 : うむ。次はこれじゃ。



// ピーター : そうそう、こんな表もありましたね。これを逆に使うんだから「符号」から「文字」に置き換えればいい んですね。でも、最初は「11111」ですが表にありませんよ?

// 博 士 : そういうときは、もっと短くするか、後ろとつなげるかしてみるのだよ。

// ピ ー タ ー : じゃあ短くして......あ、 「111」ならあります。じゃあ最初は「P」ですね。そうすると残りは「11」ですが、 これはぴったり合うのがないから次の「00011」から 1 文字借りて「110」にすればいいんですね。

// 博 士 : そうそう。つまり「E」だね。

// ピ ー タ ー : それで残るのが「0011」なので、これも次から借りて「00111」にして「T」と......。全部できました。最 後の「0000」は捨てちゃえばいいんですよね?



// 博 士 : そうじゃ、よろしい。次はこれじゃ。

// ?D-C'?-C'-LMGZN?FNJKN- WEYN?P'QMRWLPZLKKTPOVRGDI
// 博 士 : さらにこれじゃ。

// ?P'QNPY?IXX?IXXK.BI -G?R'RPP'RPOVWDMW?SWUVG'-LCMGQ
// 博 士 : 仕上げにこうじゃ。

// ?P'QMDUEQ GADKOQ ?SWUVG'-LCMG?X?IGX,PUL.?UL.VNQQI
// ピ ー タ ー : しっかし面倒だなあ。博士、今度は自分でプログラムを作って下さいよ。

// ということで、博士のかわりに、上の文章を置き換えるプログラムを作成してください。

// Input
// 複数のデータセットが与えられます。各データセットとして、１つの文字列（表に含まれる文字からなる 200 文字以下の文字列）が１行に与えられます。入力の終わりまで処理してください。データセットの数は 200 を超えません。

// Output
// 各データセットごとに、変換後の文字列を１行に出力してください。

// from aoj0088

#include <bits/stdc++.h>
using namespace std;
pair<char,string> list1[] = {
{'\'',	"000000"},
{'?',	"000001"},
{'W',	"000010"},
{',',	"000011"},
{'D',	"0001"},
{'L',	"00100"},
{'O',	"00101"},
{'S',	"00110"},
{'T',	"00111"},
{'.',	"010001"},
{'H',	"010000"},
{'F',	"01001"},
{'C',	"0101"},
{'K',	"0110"},
{'I',	"0111"},
{'R',	"1000"},
{'Z',	"10010000"},
{'-',	"10010001"},
{'X',	"10010010"},
{'Y',	"10010011"},
{'A',	"100101"},
{'J',	"10011000"},
{'M',	"10011001"},
{'B',	"10011010"},
{'G',	"10011011"},
{'U',	"10011100"},
{'V',	"10011101"},
{'N',	"10011110"},
{'Q',	"10011111"},
{' ',	"101"},
{'E',	"110"},
{'P',	"111"}
};

pair<string,char> list2[] = {
{"00000",	'A'},
{"00001",	'B'},
{"00010",	'C'},
{"00011",	'D'},
{"00100",	'E'},
{"00101",	'F'},
{"00110",	'G'},
{"00111",	'H'},
{"01000",	'I'},
{"01001",	'J'},
{"01010",	'K'},
{"01011",	'L'},
{"01100",	'M'},
{"01101",	'N'},
{"01110",	'O'},
{"01111",	'P'},
{"10000",	'Q'},
{"10001",	'R'},
{"10010",	'S'},
{"10011",	'T'},
{"10100",	'U'},
{"10101",	'V'},
{"10110",	'W'},
{"10111",	'X'},
{"11000",	'Y'},
{"11001",	'Z'},
{"11010",	' '},
{"11011",	'.'},
{"11100",	','},
{"11101",	'-'},
{"11110",	'\''},
{"11111",	'?'}
};
int main() {
    string s;
    while (getline(cin,s)) {
        string code = "";
        for (int i = 0; i < s.size(); i++) {
            for (auto p:list2) {
                if (s[i] == p.second) {
                    code += p.first;
                    break;
                }
            }
        }
        string ans = "";
        int pos = 0;
        while (pos < code.size()) {
            bool ok;
            bool ad = 0;
            for (auto p:list1) {
                ok = 1;
                if (p.second.size() + pos > code.size()) continue;
                for (int i = 0; i < p.second.size(); i++) {
                    if (code[pos+i] != p.second[i]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ad = 1;
                    ans += p.first;
                    pos += p.second.size();
                    break;
                }
            }
            if (!ad) break;
        }
        cout << ans << endl;
    }
    return 0;
}