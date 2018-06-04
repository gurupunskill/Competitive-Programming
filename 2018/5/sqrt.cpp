#include <bits/stdc++.h>
using namespace std;

int mysqrt(int x) {

    if (x == 0 || x == 1) {
        return x;
    }
    long start = 1, end = x;
    long mid, ans;

    while(start <= end) {
        mid = start + end;
        mid /= 2;

        if (mid*mid == x) {
            return mid;
        }
        else if (mid*mid > x) {
            end = mid-1;
        }
        else {
            start = mid+1;
            ans = mid;
        }   
    }
    return (unsigned int) ans;
}

int main() {
    int x;
    cin >> x;
    cout << mysqrt(x) << endl;
    return 0;
}