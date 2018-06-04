#include<bits/stdc++.h>
using namespace std;

void rotate_matrix(vector< vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();

    int i, j;

    // Transpose matrix
    for (i = 0; i < m; i++) {
        for (j = i; j < n; j++) {
            int tmp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = tmp;
        }
    }

    // Reverse rows
    for (i = 0; i < n; i++) {
        reverse(A[i].begin(), A[i].end());
    }
}

int main() {
    int n = 3;
    vector < vector<int> > A(n, vector<int> (n, 0));
    int count = 1;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = count++;
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    rotate_matrix(A);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}