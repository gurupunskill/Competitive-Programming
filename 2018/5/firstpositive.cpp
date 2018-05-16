#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A) {
    int i = 0;
    int j = 0;
    int n = A.size();

    while (i < n && j < n) {
        if (A[j] <= 0) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            //cout << i << endl;
        }
        j++;
    }

    return i;
}

int actual(vector<int> &A) {
    int n = A.size();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        if (abs(A[i]) <= n) {
            A[abs(A[i])-1] = -abs(A[abs(A[i])-1]);
            cout << "Changing " << abs(A[i])-1 << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            return i+1;
        }
    }
    return n+1;
}

int firstMissingPositive(vector<int> &A) {
    int start = partition(A);
    vector<int> B (A.begin()+start, A.end());
    return actual(B);
}

int main() {
    vector<int> A = {1};
    int a = firstMissingPositive(A);
    cout << a << endl;
    return 0;
}
