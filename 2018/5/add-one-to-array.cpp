#include<bits/stdc++.h>
using namespace std;

vector<int> add_one(vector <int> A) {
    int n = A.size();
    int carry = 0;
    A[n-1] += 1;
    carry = A[n-1]/10;
    A[n-1] = A[n-1]%10;
    for (int i = n-2; i >= 0; i--) {
        A[i] += (carry);
        carry = A[i]/10;
        A[i] = A[i]%10;
    }

    if (carry != 0) {
        A.insert(A.begin(), carry);
    }

    vector<int>::iterator a = A.begin();

    while (*a == 0) {
        a++;
    }

    vector<int> B;
    B.assign(a, A.end());

    return B;
}

int main() {
    vector<int> A = {0, 0, 0, 1, 2, 9, 9, 9};
    add_one(A);
    return 0;
}