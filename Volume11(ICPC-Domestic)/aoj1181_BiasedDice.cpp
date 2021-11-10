#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif


struct Dice{
    int ue, st, me, usr, hdr, mg;
    Dice(){}
    Dice (int ue, int me, int mg, int hdr, int usr, int st) :
        ue(ue), st(st), me(me), usr(usr), hdr(hdr), mg(mg) {}
    Dice Roll (char c);
    bool operator==(const Dice& b) const {
        return (ue == b.ue && st == b.st && me == b.me && usr == b.usr && hdr == b.hdr && mg == b.mg);
    }
    const bool operator < (const Dice& other) const {
        if (ue != other.ue) return ue < other.ue;
        if (st != other.st) return st < other.st;
        if (me != other.me) return me < other.me;
        if (usr != other.usr) return usr < other.usr;
        if (hdr != other.hdr) return hdr < other.hdr;
        return mg < other.mg;
    }
};

Dice Dice::Roll (char c) {
    int t1 = ue;
    int t2 = me;
    int t3 = mg;
    int t4 = hdr;
    int t5 = usr;
    int t6 = st;
    if (c == 'S') {
        ue = t5;
        st = t2;
        me = t1;
        usr = t6;
        hdr = t4;
        mg = t3;
    } else if (c == 'N') {
        ue = t2;
        st = t5;
        me = t6;
        usr = t1;
        hdr = t4;
        mg = t3;
    } else if (c == 'W') {
        ue = t3;
        st = t4;
        me = t2;
        usr = t5;
        hdr = t1;
        mg = t6;
    } else if (c == 'E') {
        ue = t4;
        st = t3;
        me = t2;
        usr = t5;
        hdr = t6;
        mg = t1;
    } else {
        ue = t1;
        st = t6;
        me = t3;
        usr = t4;
        hdr = t2;
        mg = t5;
    }
    return *this;
}

int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};
string str_dir = "NESW ";

void go(Dice dice, int h, int w, VV<int>& height, VV<int>& num, V<int>& cnt) {

    int dir = -1;
    int dir_no = 3;
    rep(i,0,4) {
        int th = h + dh[i];
        int tw = w + dw[i];
        if (height[th][tw] >= height[h][w]) continue;
        int no;
        switch (i) {
            case 0:
                no = dice.usr;
                break;
            case 1:
                no = dice.mg;
                break;
            case 2:
                no = dice.me;
                break;
            default:
                no = dice.hdr;
        }
        if (no > dir_no) {
            dir_no = no;
            dir = i;
        }
    }

    if (dir_no > 3) go(dice.Roll(str_dir[dir]), h + dh[dir], w + dw[dir], height, num, cnt);
    else {
        height[h][w]++;
        cnt[num[h][w]]--;
        cnt[dice.ue]++;
        num[h][w] = dice.ue;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    Dice dice(1,3,5,2,4,6);

    map<pair<int,int>, Dice> mp;
    mp[{1,3}] = dice;
    rep(i,0,4) {
        dice.Roll(' ');
        mp[{dice.ue, dice.me}] = dice;
        rep(j,0,4) {
            dice.Roll('N');
            mp[{dice.ue, dice.me}] = dice;
        }
        rep(j,0,4) {
            dice.Roll('W');
            mp[{dice.ue, dice.me}] = dice;
        }
    }


    int n;
    while (cin >> n, n) {
        VV<int> height(500,V<int>(500));
        VV<int> num(500,V<int>(500));
        V<int> cnt(7);
        rep(i,0,n) {
            int t,f;
            cin >> t >> f;
            go(mp[{t,f}],250,250,height,num,cnt);
        }
        rep(i,1,7) cout << cnt[i] << " \n"[i == 6];

    }
    
    
    return 0;
}