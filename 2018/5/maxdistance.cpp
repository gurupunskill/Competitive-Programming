// https://www.interviewbit.com/problems/max-distance/

#include<bits/stdc++.h>
using namespace std;

int maxDistance (vector<int> A) {
    int n = A.size();
    vector<int> maxRight(n);
    vector<int> minLeft(n);
    
    maxRight[n-1] = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (A[i] > A[maxRight[i+1]]) {
            maxRight[i] = i;
        }
        else {
            maxRight[i] = maxRight[i+1];
        }
    }

    minLeft[0] = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[minLeft[i-1]]) {
            minLeft[i] = i;
        }
        else {
            minLeft[i] = minLeft[i-1];
        }
    }

    int maximum = -1;

    /*for (int i = 0; i < n; i++) {
        cout << minLeft[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << maxRight[i] << " ";
    }
    cout << endl;
    */

    int i = 0, j = 0;
    while(i < n && j < n) {
        if (A[maxRight[j]] > A[minLeft[i]]){
            maximum = max(maximum, maxRight[j] - minLeft[i]);
            j++;
        }
        else {
            i++;
        }
    }

    return maximum;
}


int main() {
    int n, a;
    cin >> n;
    vector<int> A;
    while(n--)
    {
        cin >> a;
        A.push_back(a);
    }
    cout << maxDistance(A) << endl;
    return 0;
}