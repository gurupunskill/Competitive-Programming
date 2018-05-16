#include <bits/stdc++.h>
using namespace std;

void set_zeros(vector< vector<int> > A) {

    int i, j;
    int m = A.size();
    int n = A[0].size();

    bool top_row = false;
    bool top_col = false;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {

            if (A[0][j] == 0) {
                top_row = true;
            }

            if (A[i][0] == 0) {
                top_col = true;
            }

            if (A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }

    for (i = 1; i < m; i++) {
        if (A[i][0] == 0) {
            for (j = 1; j < n; j++) {
                A[i][j] = 0;
            }
        }
    }

    for (j = 1; j < n; j++) {
        if (A[0][j] == 0) {
            for (i = 1; i < m; i++) {
                A[i][j] = 0;
            }
        }
    }

    if (top_row) {
        for (j = 0; j < n; j++) {
            A[0][j] = 0;
        }
    }
    if (top_col) {
        for (i = 0; i < m; i++) {
            A[i][0] = 0;
        }
    }

}