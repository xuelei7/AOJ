// Problem G: Surface Area of Cubes
// Taro likes a single player game "Surface Area of Cubes".

// In this game, he initially has an $A \times B \times C$ rectangular solid formed by $A \times B \times C$ unit cubes (which are all 1 by 1 by 1 cubes). The center of each unit cube is placed at 3-dimentional coordinates $(x, y, z)$ where $x$, $y$, $z$ are all integers ($0 \leq x \leq A-1, 0 \leq y \leq B -1, 0 \leq z \leq C - 1$). Then, $N$ distinct unit cubes are removed from the rectangular solid by the game master. After the $N$ cubes are removed, he must precisely tell the total surface area of this object in order to win the game.

// Note that the removing operation does not change the positions of the cubes which are not removed. Also, not only the cubes on the surface of the rectangular solid but also the cubes at the inside can be removed. Moreover, the object can be divided into multiple parts by the removal of the cubes. Notice that a player of this game also has to count up the surface areas which are not accessible from the outside.

// Taro knows how many and which cubes were removed but this game is very difficult for him, so he wants to win this game by cheating! You are Taro's friend, and your job is to make a program to calculate the total surface area of the object on behalf of Taro when you are given the size of the rectangular solid and the coordinates of the removed cubes.

// Input
// The input is formatted as follows.

// The first line of a test case contains four integers $A$, $B$, $C$, and $N$ ($1 \leq A, B, C \leq 10^8, 0 \leq N \leq $ min{$1,000, A \times B \times C - 1$}).

// Each of the next $N$ lines contains non-negative integers $x$, $y$, and $z$ which represent the coordinate of a removed cube. You may assume that these coordinates are distinct.

// Output
// Output the total surface area of the object from which the $N$ cubes were removed.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* ????????????????????????????????????????????? */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

auto solve (ll A, ll B, ll C, ll N, V<ll>& X, V<ll>& Y, V<ll>& Z) -> ll {
    struct Face{
        // 0: front
        // 1: left
        // 2: down
        ll x, y, z, id;
        Face(ll x, ll y, ll z, ll id):x(x),y(y),z(z),id(id) {}
        bool operator <(const Face& f) const {
            if (x != f.x) return x < f.x;
            if (y != f.y) return y < f.y;
            if (z != f.z) return z < f.z;
            return id < f.id;
        }
    };
    
    // ???????????????????????????????????????
    map<Face,int> mp;
    rep(i,0,N) {
        ll x = X[i], y = Y[i], z = Z[i];
        // ????????????????????????
        rep(j,0,3) mp[Face(x,y,z,j)]++;
        // ???
        mp[Face(x,y+1,z,2)]++;
        // ???
        mp[Face(x+1,y,z,1)]++;
        // ??????
        mp[Face(x,y,z+1,0)]++;
    }

    auto in = [&](Face f) -> bool {
        if ((f.x == 0 || f.x == A) && f.id == 1) return false; // left
        if ((f.y == 0 || f.y == B) && f.id == 2) return false; // down
        if ((f.z == 0 || f.z == C) && f.id == 0) return false; // front
        return true;
    };

    // ?????????????????????
    ll ans = (A * B + A * C + B * C) * 2LL;
    for (auto p: mp) {
        Face face = p.first;
        ll cnt = p.second;

        // face??????????????????????????????????????????
        bool inside = in(face);

        // ???????????????1??????ans+=1???2??????????????????
        if (inside) {
            ans += (2 - cnt);
        }
        // ???????????????ans-=1
        else {
            ans--;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    ll A, B, C, N;
    cin >> A >> B >> C >> N;
    V<ll> X(N), Y(N), Z(N);
    rep(i,0,N) {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    // solve
    auto ans = solve(A,B,C,N,X,Y,Z);

    // output
    cout << ans << endl;
    
    return 0;
}