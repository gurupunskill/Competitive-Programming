#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > spiral(int n) {
    vector< vector<int> > matrix(n, vector<int>(n));

    int row_top = 0, row_end = n-1, column_top = 0, column_end = n-1;
    int count = 1;
    int i, j;
    while ( count <= n*n ) {
        // Fill out first row
        for (i = column_top; i <= column_end; i++) {
            matrix[row_top][i] = count++;
        }

        // fill out last column
        for (i = row_top+1; i <= row_end; i++) {
            matrix[i][column_end] = count++;
        }

        // fill out bottom row
        for (i = column_end-1; i >= column_top; i--) {
            matrix[row_end][i] = count++;
        }

        // fill out first column
        for (i = row_end-1; i > row_top; i--) {
            matrix[i][column_top] = count++;
        }

        row_end--;
        row_top++;
        column_end--;
        column_top++;
    }

    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

int main() {
    spiral(6);
    return 0;
}