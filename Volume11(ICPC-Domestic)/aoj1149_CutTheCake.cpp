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

struct cake{
    int area, w, h;
    cake(){}
    cake(int a, int w, int h): area(a), w(w), h(h) {}
    bool operator < (const cake& other) const {
        return area < other.area;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,w,h;
    while (cin >> n >> w >> h, h) {
        V<cake> v;
        v.push_back(cake(w*h,w,h));
        rep(i,1,n+1) {
            int p,s;
            cin >> p >> s;
            p--;
            cake ck = v[p];
            s %= ck.h + ck.w;
            cake c1, c2;
            // |
            if (s < ck.w) {
                c1 = cake(s*ck.h, s, ck.h);
                c2 = cake((ck.w-s)*ck.h, ck.w-s, ck.h);
            }
            // -
            else {
                s -= ck.w;
                c1 = cake(s*ck.w, ck.w, s);
                c2 = cake((ck.h-s)*ck.w, ck.w, ck.h-s);
            }
            if (c1.area > c2.area) swap(c1, c2);
            V<cake> tmp;
            rep(j,0,i) {
                if (j == p) continue;
                tmp.push_back(v[j]);
            }
            tmp.push_back(c1);
            tmp.push_back(c2);
            v.clear();
            rep(j,0,i+1) {
                v.push_back(tmp[j]);
            }
        }
        sort(all(v));
        rep(i,0,n+1) {
            cout << v[i].area << " \n"[i==n];
        }
    }
    
    return 0;
}