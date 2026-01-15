#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long lcmm(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {

        long long low = 1;
        long long high = 2e18;

        long long ab = lcmm(a, b);
        long long bc = lcmm(b, c);
        long long ac = lcmm(a, c);
        long long mtpl = lcmm(ab, c);   

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long cnt =
                mid / a + mid / b + mid / c
                - mid / ab - mid / bc - mid / ac
                + mid / mtpl;

            if (cnt < n)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
