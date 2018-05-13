// https://www.interviewbit.com/problems/maximum-absolute-difference/

#include <bits/stdc++.h>
using namespace std;

int mad(vector<int> A) {

    int n = A.size();
    int minus_max = INT_MIN;
    int minus_min = INT_MAX;
    int plus_max = INT_MIN;
    int plus_min = INT_MAX;

    for (int i = 0; i < n; i++) {
        minus_max = max(minus_max, A[i] - i);
        minus_min = min(minus_min, A[i] - i);
        plus_max  = max(plus_max , A[i] + i);
        plus_min  = min(plus_min , A[i] + i);
    }

    int max1 = plus_max - plus_min;
    int max2 = minus_max - minus_min;

    return max(max1, max2);
}