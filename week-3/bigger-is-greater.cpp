#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define all(a) a.begin(),a.end()

int main() 
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        
        if (next_permutation(all(s)))
            cout << s << endl;
        else cout << "no answer" << endl;
    }
    return 0;
}