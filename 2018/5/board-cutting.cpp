// https://www.hackerrank.com/challenges/board-cutting/problem

#include <bits/stdc++.h>

using namespace std;

long boardCutting(long m, long n, vector <long> cost_y, vector <long> cost_x) {
    sort (cost_y.rbegin(), cost_y.rend());
    sort (cost_x.rbegin(), cost_x.rend());
    long hor_piece = 1;
    long ver_piece = 1;
    long cost = 0;
    vector<long>::iterator y = cost_y.begin();
    vector<long>::iterator x = cost_x.begin();
    
    while (y != cost_y.end() || x != cost_x.end()) {
        if ((*y > *x || x == cost_x.end()) && y != cost_y.end()) {
            cost += (*y)*ver_piece;
            hor_piece += 1;
            y++;
        }
        else {
            cost += (*x)*hor_piece;
            ver_piece += 1;
            x++;
        }
    }

    return (cost%(1000000007));
}

int main() {
    long q;
    cin >> q;
    for(long a0 = 0; a0 < q; a0++){
        long m;
        long n;
        cin >> m >> n;
        vector<long> cost_y(m-1);
        for(long cost_y_i = 0; cost_y_i < m-1; cost_y_i++){
           cin >> cost_y[cost_y_i];
        }
        vector<long> cost_x(n-1);
        for(long cost_x_i = 0; cost_x_i < n-1; cost_x_i++){
           cin >> cost_x[cost_x_i];
        }
        long result = boardCutting(m, n, cost_y, cost_x);
        cout << result << endl;
    }
    return 0;
}
