// https://www.hackerrank.com/challenges/the-hurdle-race/problem
#include <bits/stdc++.h>

using namespace std;

int hurdleRace(int k, vector <int> height) {
    // Complete this function
    int max = *max_element(height.begin(), height.end());
    if (max <= k)
        return 0;
    else return (max - k);
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    int result = hurdleRace(k, height);
    cout << result << endl;
    return 0;
}
