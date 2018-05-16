// https://www.interviewbit.com/problems/pascal-triangle/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > generate(int n) {

    vector< vector<int> > triangle;
    for (int i = 0; i < n; i++) {
        vector<int> current_row;
        int value = 1;
        current_row.push_back(value);
        for (int j = 1; j <= i; j++) {
            value *= (i-j+1);
            value /= j;
            current_row.push_back(value);
        }
        triangle.push_back(current_row);
    }
    
    return triangle;
}
