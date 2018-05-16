// https://www.interviewbit.com/problems/largest-number/

#include<bits/stdc++.h>
using namespace std;

int comparator(int a, int b) {
    string One = to_string(a);
    string Two = to_string(b);
    string OneTwo = One.append(Two);
    string TwoOne = Two.append(One);
        
    return (OneTwo.compare(TwoOne) > 0 ? 1:0);
}

string largestNumber(const vector<int> &N) {
    
    vector<int> A(N);
    sort(A.begin(), A.end(), comparator);
    string ans = "";
    
    for (vector<int>::const_iterator i = A.begin(); i != A.end(); i++) {
        ans.append(to_string(*i));
    }
    
    return ans;
}

int main() {
    vector<int> A = {3, 30, 34, 5, 9};
    cout << largestNumber(A);
    return 0;
}


