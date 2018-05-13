// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

#include <bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int> A) {
    int actual_max = INT_MIN;
    int current_max = 0;

    for (vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        current_max += *i;
        if (actual_max < current_max) {
            actual_max = current_max;
        }
        if (current_max < 0) {
            current_max = 0;
        }
    }
    return actual_max;
}

int main() {
    vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(A) << endl;
    return 0;
}