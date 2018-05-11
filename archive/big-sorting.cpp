#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
/* This question is bullshit af */

bool comparator(string a, string b)
{
    int la = a.length();
    int lb = b.length();
    if (la == lb)
        return a < b;
    else 
        return la < lb;
}

int main()
{
    int n;
    cin >> n;

    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++)
    {
       cin >> unsorted[unsorted_i];
    }

    sort (all(unsorted), comparator);

    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++)
    {
       cout << unsorted[unsorted_i] << endl;
    }
    return 0;
}
