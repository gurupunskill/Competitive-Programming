#include<bits/stdc++.h>
using namespace std;

vector<int> flip(string A) {
    // Use kedane's algorithm to find the ideal positions
    int cur_start, cur_end;
    int max_start, max_end;

    int cur_max = 0;
    int act_max = INT_MIN;
    // I need to find subarray with maximum 0
    cur_start = 0;
    cur_end = 0;
    for (string::iterator i = A.begin(); i != A.end(); i++) {
        if (*i == '0') {
            cur_max += 1;
            cur_end += 1;
        }
        else {
            cur_max -= 1;
            cur_end += 1;
        }

        if (cur_max < 0) {
            cur_max = 0;
            cur_start = cur_end;
        }

        if (cur_max > act_max) {
            act_max = cur_max;
            max_start = cur_start;
            max_end = cur_end;
        }
    }

    vector<int> ans;
    ans.push_back(max_start+1);
    ans.push_back(max_end);
    return ans;
}