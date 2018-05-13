// http://www.spoj.com/problems/HISTOGRA/

#include <bits/stdc++.h>
using namespace std;

long largest_rectangle(vector<long> histogram){
    stack<long> Stack;

    long maximum = 0;
    histogram.insert(histogram.begin(), -1);
    histogram.push_back(-1);

    Stack.push(0);

    long n = histogram.size();
    long area, top;
    for (long i = 0; i < n; i++) {
        while(histogram[i] < histogram[Stack.top()]) {
            top = Stack.top();
            Stack.pop();
            area = histogram[top]*(i-Stack.top()-1);
            maximum = max(area, maximum);
        }
        Stack.push(i);
    }
    return maximum;
}

int main(){

    long n;
    cin >> n;

    while(n != 0) {
        vector<long> histogram(n);
        for (long i = 0; i < n; i++) {
            cin >> histogram[i];
        }
        cout << largest_rectangle(histogram) << endl;
        cin >> n;
    }
    return 0;
}