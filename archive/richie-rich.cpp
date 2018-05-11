#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    
    string left(s.begin(), s.begin() + n/2);
    string right(s.begin() + n/2, s.end());

        //cout << left << " " << right << endl;

    return 0;
}