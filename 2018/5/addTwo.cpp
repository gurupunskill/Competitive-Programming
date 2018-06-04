#include<bits/stdc++.h>
using namespace std;

long long add_(long long a, long long b){
    long long carry;
    while (b > 0){
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main() {
    long long x, y;
    cin >> x >> y;
    cout << add_(x,y);
    return 0;
}