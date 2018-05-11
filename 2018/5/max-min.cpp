// https://www.hackerrank.com/challenges/angry-children/problem
#include <bits/stdc++.h>

using namespace std;

long angryChildren(long k, vector <long> arr) {

    /*
        Greedy Strategy:
        1. Sort arr.
        2. Set up a "filter" of size k that finds the difference of both ends
        3. Return filter with minimm value
    */

   sort(arr.begin(), arr.end());
   long min = LONG_MAX;
   for (vector<long>::iterator a = arr.begin(); a != arr.end()-k+1; a++) {
       if (*(a+k-1) - *a < min) {
           min = *(a+k-1) - *(a);
       }
   }
   return min;

}

int main() {
    long n;
    cin >> n;
    long k;
    cin >> k;
    vector<long> arr(n);
    for(long arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long result = angryChildren(k, arr);
    cout << result << endl;
    return 0;
}
// 9665150