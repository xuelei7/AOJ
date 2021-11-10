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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    while (cin >> n >> m, n) {
        // record
        int r;
        cin >> r;
        VV<pair<int,int>> timetable(m);
        rep(i,0,r) {
            int time, pc, stu, sta;
            cin >> time >> pc >> stu >> sta;
            stu--;
            timetable[stu].push_back({time,-sta});
        }

        // query
        int q;
        cin >> q;
        while (q--) {
            int bg,ed,stu;
            cin >> bg >> ed >> stu;
            stu--;
            auto records = timetable[stu];
            sort(all(records));
            // cout << "------" << endl;
            // cout << stu << ": " << records.size() << endl;
            // for (auto record: records) {
            //     cout << record.first << " " << record.second << endl;
            // }
            // cout << "--" << endl;
            int pc_cnt = 0;
            int starttime = 1e9;
            int ret = 0;
            for (auto record: records) {
                if (record.second == -1) { // login
                    if (pc_cnt == 0) starttime = record.first;
                    pc_cnt++;
                } else { // logout
                    pc_cnt--;
                    if (pc_cnt != 0) continue;
                    // pc_cnt == 0
                    // cout << "    " << starttime << " " << record.first << endl;
                    if (record.first <= bg) {                        
                        // do nothing
                    } else if (record.first <= ed) {
                        ret += record.first - max(starttime, bg);
                    } else if (record.first > ed) {
                        if (starttime < ed)
                            ret += min(record.first, ed) - max(starttime, bg);
                    }
                    starttime = 1e9;
                }
            }
            cout << ret << endl;
        }
    }
    
    return 0;
}