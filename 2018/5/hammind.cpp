#include <bits/stdc++.h>
using namespace std;

int hammingDistance(const vector<int> &A) {
    long long ans = 0;
    long count = 0;
    long n = A.size();
    for (int i = 0; i < 32; i++) {
        count = 0;
        vector<int>::const_iterator j = A.begin();
        for (; j != A.end(); j++) {
            if (*j & (1<<i)){
                count ++;
            }
        }
        ans += count*(n-count)*2;
    }
    int val = ans%(1000000007);
    return val;
}
