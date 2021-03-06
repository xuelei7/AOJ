// Problem B: Erratic Sleep Habits
// Peter is a person with erratic sleep habits. He goes to sleep at twelve o'lock every midnight. He gets up just after one hour of sleep on some days; he may even sleep for twenty-three hours on other days. His sleeping duration changes in a cycle, where he always sleeps for only one hour on the first day of the cycle.

// Unfortunately, he has some job interviews this month. No doubt he wants to be in time for them. He can take anhydrous caffeine to reset his sleeping cycle to the beginning of the cycle anytime. Then he will wake up after one hour of sleep when he takes caffeine. But of course he wants to avoid taking caffeine as possible, since it may affect his health and accordingly his very important job interviews.

// Your task is to write a program that reports the minimum amount of caffeine required for Peter to attend all his interviews without being late, where the information about the cycle and the schedule of his interviews are given. The time for move to the place of each interview should be considered negligible.

// Input
// The input consists of multiple datasets. Each dataset is given in the following format:

// T
// t1 t2 ... tT
// N
// D1 M1
// D2 M2
// ...
// DN MN
// T is the length of the cycle (1 ≤ T ≤ 30); ti (for 1 ≤ i ≤ T ) is the amount of sleep on the i-th day of the cycle, given in hours (1 ≤ ti ≤ 23); N is the number of interviews (1 ≤ N ≤ 100); Dj (for 1 ≤ j ≤ N) is the day of the j-th interview (1 ≤ Dj ≤ 100); Mj (for 1 ≤ j ≤ N) is the hour when the j-th interview starts (1 ≤ Mj ≤ 23).

// The numbers in the input are all integers. t1 is always 1 as stated above. The day indicated by 1 is the first day in the cycle of Peter's sleep.

// The last dataset is followed by a line containing one zero. This line is not a part of any dataset and should not be processed.

// Output
// For each dataset, print the minimum number of times Peter needs to take anhydrous caffeine.

#include <bits/stdc++.h>
using namespace std;
int T,N;
int t[35],m[110];
int dp[210];

int main() {
    while (cin >> T) {
        if (T == 0) break;
        for (int i = 0; i < T; i++) {
            cin >> t[i];
        }
        cin >> N;
        memset(m,0,sizeof(m));
        for (int i = 0; i <= 200; i++) dp[i] = 200;
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            int d,mm;
            cin >> d >> mm;
            if (m[d] == 0) m[d] = mm;
            else m[d] = min(m[d],mm);
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 1; j <= 100; j++) {
                if (m[i+j] == 0 || t[(j-1)%T] <= m[i+j]) {
                    dp[i+j] = min(dp[i+j], dp[i] + 1);
                } else {
                    break;
                }
            }
        }
        // for (int i = 0; i < 10; i++) {
        //     for (int j = 0; j < 10; j++) {
        //         cout << dp[i*10+j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        cout << dp[100] - 1 << endl;
    }
}