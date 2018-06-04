#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B) {
    int x = A.length();
    int y = B.length();
    
    if (x == 0) {
        return B;
    }
    else if (y == 0) {
        return A;
    }
    
    string result;
    
    int i = x-1, j = y-1;
    int a, b, c = 0;
    int sum;
    while (i >= 0 || j >= 0) {
        
        if (i != -1)
            a = (A[i]) - '0';
        else 
            a = 0;
            
        if (j != -1)
            b = (B[j]) - '0';
        else 
            b = 0;
        
        sum = a + b + c;
        c = sum/2;
        sum = sum%2;
        
        //cout << sum << " " << c << endl;
        result.push_back('0' + sum);
        
        i--;
        if (i < 0) i = -1;
        j--;
        if (j < 0) j = -1;
    }

    //cout << c << endl;
    if (c != 0) result.push_back('0' + c);
    
    reverse(result.begin(), result.end());
    return result;
}


int main() {
    cout << endl << addBinary("1", "1");
    return 0;
}