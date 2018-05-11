#include <bits/stdc++.h>

using namespace std;

int find_closest(int diff) {
    if (diff >= 3) {
        if (diff >= 5) {
            return 5;
        }
        else {
            return 3;
        }
    }
    else {
        return 1;
    }
}

int equal(vector <int> arr, int n) {
    int count = 0;
    sort(arr.begin(), arr.end());
    for(int j = 0; j < n; j++)
    for(int i = 0; i < n-1; i++) {
        int diff = arr[i+1] - arr[i];
        if (diff > 0) {
            diff = find_closest(diff);
            arr[i+1] -= diff;
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = equal(arr, n);
        cout << result << endl;
    }
    return 0;
}
