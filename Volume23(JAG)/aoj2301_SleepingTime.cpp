// Sleeping Time
// Miki is a high school student. She has a part time job, so she cannot take enough sleep on weekdays. She wants to take good sleep on holidays, but she doesn't know the best length of sleeping time for her. She is now trying to figure that out with the following algorithm:

// Begin with the numbers K, R and L.
// She tries to sleep for H=(R+L)⁄2 hours.
// If she feels the time is longer than or equal to the optimal length, then update L with H. Otherwise, update R with H.
// After repeating step 2 and 3 for K nights, she decides her optimal sleeping time to be T'=(R+L)⁄2.
// If her feeling is always correct, the steps described above should give her a very accurate optimal sleeping time. But unfortunately, she makes mistake in step 3 with the probability P.

// Assume you know the optimal sleeping time T for Miki. You have to calculate the probability PP that the absolute difference of T' and T is smaller or equal to E. It is guaranteed that the answer remains unaffected by the change of E in 10−10.

// Input
// The input follows the format shown below

// K R L
// P
// E
// T
// Where the integers 0≤K≤30, 0≤R≤L≤12 are the parameters for the algorithm described above. The decimal numbers on the following three lines of the input gives the parameters for the estimation. You can assume 0≤P≤1, 0≤E≤12, 0≤T≤12.

// Output
// Output PP in one line. The output should not contain an error greater than 10−5.

#include <bits/stdc++.h>
using namespace std;
double eps = 1e-10;
int k;
double r,l,p,e,t;
double dfs(double a, double b, int kk) {
    if (kk == k) {
        double h = (a + b) / 2.0;
        // cout << "k " << a << " " << b << " " << h << " " << (abs(h - t) <= e) << endl;
        return abs(h - t) <= e;
    }
    if (a > t - e - eps && b < t + e + eps) {
        // cout << "a " << a << " " << b << " " << 1 << endl;
        return 1.0;
    }
    if (b < t - e - eps || a > t + e + eps) {
        // cout << "b " << a << " " << b << " " << 0 << endl;
        return 0;
    }
    double h = (a + b) / 2.0;
    // cout << a << " " << b << " " << h << endl;
    if (h >= t) {
        double ret = (1.0 - p) * dfs(a,h,kk+1) + p * dfs(h,b,kk+1);
        // cout << "c " << a << " " << b << " " << ret << endl;
        return ret;
    } else {
        double ret = (1.0 - p) * dfs(h,b,kk+1) + p * dfs(a,h,kk+1);
        // cout << "d " << a << " " << b << " " << ret << endl;
        return ret;
    }
}

int main() {
    cin >> k >> l >> r >> p >> e >> t;
    cout << fixed << setprecision(20) << dfs(l,r,0) << endl;
    return 0;
}