#include <bits/stdc++.h>
using namespace std;

int maximum_gap(vector<int> A) {
    int min = *(min_element(A.begin(), A.end()));
    int maxn = *(max_element(A.begin(), A.end()));

    int diff = maxn - min;

    int n = A.size();
    if (n < 2)
        return;
    vector<vector<int> > buckets(n-1);
    float delta = diff/(n-1);

    int k;
    for (vector<int>::iterator i = A.begin(); i != A.end(); i++) {
        k = (*i - min)/delta;
        if (*i == min) {
            k = 1;
        }
        buckets[k-1].push_back(*i);
    }

    vector<int> minarray(n-1, NULL);
    vector<int> maxarray(n-1, NULL);

    for (int i = 0; i < n-1; i++) {
        if (buckets[i].size() == 0)
            continue;
        minarray[i] = (*(min_element(buckets[i].begin(), buckets[i].end())));
        maxarray[i] = (*(max_element(buckets[i].begin(), buckets[i].end())));
    }
    int maxans = INT_MIN;
    for (int i = 0; i < n-2; i++) {
        if (maxarray[i] == NULL || minarray[i+1] == NULL) {
            continue;
        }
        maxans = max(maxans, maxarray[i] - minarray[i+1]); 
    } 
    return abs(maxans);
}

int main() {
    vector<int> A = {1, 10, 5, 25};
    cout << maximum_gap(A);
    return 0;
}