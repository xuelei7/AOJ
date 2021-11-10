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

int n;
V<string> v(20);
V<int> val(26);
V<bool> used(10);

// numberid -- row
// digit    -- col from right side
// value from lower digit   -- sum(col-1) / 10
// digit sum for this digit -- sum(col)
int f(int id, int dig, int up, int dsm) {
    char c = ' ';  // character we are looking at
    int value = -1;   // value for the character we are looking at
    
    // when there is a char, put it into c
    if (dig < v[id].size())
        c = v[id][v[id].size()-1-dig];
    // when there is no char
    else {
        if (id == n-1) { // last line -- end the searching
            return up + dsm == 0;
        } else { // not last line
            return f(id+1, dig, up, dsm);
        }
    }


    //-----------------------------------------------------------------
    /* we can say there is a char at this position we are looking at */

    // if char is decided, change value
    if (val[c-'A'] != -1)
        value = val[c-'A'];

    int ret = 0;

    for (int i = 0; i < 10; i++) {
        /*---- decide value ----*/
        // decided char -> see char-val only
        if (value != -1 && i != value) continue;
        // decided char -> when it is first digit zero
        if (value != -1 && dig == v[id].size()-1 && dig != 0 && i == 0) return 0;

        // undecided char -> see not used vals only
        if (value == -1) {
            if (used[i]) continue;
            // not a first digit zero
            if (dig == v[id].size()-1 && dig != 0 && i == 0) continue;
            // set status --> DO NOT forget to RESET them
            used[i] = 1;
            val[c-'A'] = i;
        }

        /*---- value decided ----*/


        /*---- check the arrangement ----*/
        // last row
        if (id == n-1) {
            if ((up+dsm) % 10 == i) { // ok
                ret += f(0, dig+1, (up+dsm)/10, 0);
            }
        }
        // not last row
        else {
            ret += f(id+1, dig, up, dsm+i);
        }

        if (value == -1) {
            used[i] = 0;
            val[c-'A'] = -1;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    while (cin >> n, n) {
        rep(i,0,n) cin >> v[i];
        rep(i,0,26) val[i] = -1;
        rep(i,0,10) used[i] = 0;

        cout << f(0,0,0,0) << endl;
    }
    
    return 0;
}