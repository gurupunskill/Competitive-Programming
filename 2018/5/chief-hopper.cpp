// https://www.hackerrank.com/challenges/chief-hopper/problem
#include <bits/stdc++.h>

using namespace std;

/*
    Some basic math should be able to solve this.
    At any polong E' = 2E-val
    Sum = 2*sum + val
    Req = ceil(Sum/(2**n))
*/

long chiefHopper(long n, vector <long> a) {
    
    long sum = 0;
    for (vector<long>::reverse_iterator i = a.rbegin(); i != a.rend(); i++) {
        sum = (sum+*i+1)/2;
    }
    return sum;
}

int main() {
    long n;
    cin >> n;
    vector<long> arr(n);
    for(long arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long result = chiefHopper(n, arr);
    cout << result << endl;
    return 0;
}
