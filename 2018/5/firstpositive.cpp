#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A) {
    int i = 0;
    int j = 0;
    int n = A.size();
    while (i < n && j < n) {
        if (A[j] < 0) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
        j++;
    }
    return i;
}


int firstMissingPositive(vector<int> &A) {
    int start = partition(A);
    int n = A.size();
    if (start >= n)
        return 1;
    for (int i = start; i < n; i++) {
        if (abs(A[i]) <= (n-start)) {
            A[abs(A[i])-1+start] = -abs(A[abs(A[i])-1+start]);
        }
    }
    for (int i = start; i < n; i++) {
        if (A[i] > 0) {
            return i-start+1;
        }
    }
    return n+1;
    
}
