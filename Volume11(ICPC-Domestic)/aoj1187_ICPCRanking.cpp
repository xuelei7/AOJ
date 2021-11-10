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

struct problem {
    int penalty = 0;
    bool success = 0;
    problem() {;}
};

struct record {
    int teamId;
    problem problems[11];
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int M,T,P,R;
    while (cin>>M>>T>>P>>R) {
        if (M==T && T==P && P==R && R==0) break;
        V<record> records(T);
        rep(i,0,T) records[i].teamId = i+1;
        rep(i,0,R) {
            int m,t,p,r;
            cin >> m >> t >> p >> r;
            t--;
            if (r==0) {
                records[t].problems[p].penalty += m;
                records[t].problems[p].success = 1;
            } else {
                records[t].problems[p].penalty += 20;
            }
        }

        // calc score
        V<pair<pair<int,int>,int>> v;
        for (auto r: records) {
            int score = 0;
            int cnt = 0;
            for (auto p: r.problems) {
                if (p.success) {
                    cnt++;
                    score += p.penalty;
                }
            }
            v.push_back({{-cnt,score},r.teamId});
        }
        sort(all(v));
        auto pre = v[0].first;
        V<int> vv;
        for (auto e: v) {
            if (e.first == pre) {
                vv.push_back(e.second);
            } else {
                sort(vv.rbegin(), vv.rend());
                for (int i = 0; i < vv.size(); i++) {
                    cout << vv[i] << (i!=vv.size()-1? "=":",");
                }
                vv.clear();
                pre = e.first;
                vv.push_back(e.second);
            }
        }
        sort(vv.rbegin(),vv.rend());
        for (int i = 0; i < vv.size(); i++) {
            cout << vv[i] << (i!=vv.size()-1? "=":"\n");
        }
    }
    
    return 0;
}