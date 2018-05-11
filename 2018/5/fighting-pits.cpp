// https://www.hackerrank.com/challenges/fighting-pits/problem
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> team;

int whowins (int x, int y) {
    vector<int>::iterator X = team[x-1].begin();
    vector<int>::iterator Y = team[y-1].begin();

    while (true) {
        Y += *X;
        if (Y >= team[y-1].end()) {
            return x;
        }
        X += *Y;
        if (X >= team[x-1].end()) {
            return y;
        }
    }
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    team.resize(k);
    int si, ti;
        
    for (int i = 0; i < n; i++) {
        cin >> si >> ti;
        team[ti-1].push_back(si);
    }

    for (int i = 0; i < k; i++) {
        sort(team[i].begin(), team[i].end());
    }

    int q1, q2, q3;
    while (q--) {
        cin >> q1 >> q2 >> q3;
        if (q1 == 1) {
            (team[q3-1]).push_back(q2);
            sort(team[q3-1].rbegin(), team[q3-1].rend());
        }
        else if (q1 == 2) {
            int result = whowins(q2, q3);
            cout << result << endl;
        }
    }

    return 0;
}