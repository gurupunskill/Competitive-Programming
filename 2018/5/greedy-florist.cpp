#include <bits/stdc++.h>

using namespace std;

/*
    Thank You Alwyn Sir.

    Greedy Strategy:
    1. Sort A in ascending order.
    2. For every a in A find the smallest value in B such that a+b >= k
*/

string twoArrays(int n, int k, vector <int> A, vector <int> B) {
    // Complete this function
    sort (A.begin(), A.end());
    sort (B.rbegin(), B.rend());

    for (int i = 0; i < n; i++) {
        if (A[i]+B[i] < k) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> A(n);
        for(int A_i = 0; A_i < n; A_i++){
           cin >> A[A_i];
        }
        vector<int> B(n);
        for(int B_i = 0; B_i < n; B_i++){
           cin >> B[B_i];
        }
        string result = twoArrays(n, k, A, B);
        cout << result << endl;
    }
    return 0;
}
