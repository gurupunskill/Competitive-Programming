#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()

int main() 
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    int smallest = a[1] - a[0];
    int diff;
    for (int i = 1; i < n-1; i++)
    {
        diff = a[i+1] - a[i];
        if (diff < smallest)
            smallest = diff;
    }

    for (int i = 0; i < n-1; i++)
    {
        diff = a[i+1] - a[i];
        if (diff == smallest)
            cout << a[i] << " " << a[i+1] << " ";
    }
    return 0;
}
