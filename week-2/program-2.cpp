/// https://www.hackerrank.com/challenges/caesar-cipher-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    int i = 0;
    for ( i = 0; i < n; i++ )
    {
        if (isalpha(s[i]))
        {
            int a = s[i];
            int p = (isupper(s[i]))?'A':'a';
            a = p + (a-p+k)%26;
            s[i] = a;
        }
    }

    cout << s;

    return 0;
}
