#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool sorted(vector<int> &v)
{
    for (typeof(v.begin()) i = v.begin(); i < v.end() - 1; i++)
    {
        if(*i > *(i+1))
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    int n;
    cin >> n;

    vector<int> d(n);

    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    int front, back;
    for (front = 0; front < n-1 && d[front] < d[front+1]; front++);
    for (back = n-1; back > 0 && d[back] >= d[back-1]; back--);

    swap(d[front], d[back]);
    if (sorted(d))
    {
        cout << "yes\nswap " << front+1 << " " << back+1;
    }


    else
    {
        swap(d[front], d[back]);        
        vector<int>::iterator f = d.begin() + front;
        vector<int>::iterator b = d.begin() + back + 1;
        reverse(f,b);
        if (sorted(d))
        {
            cout << "yes\nreverse " << front+1 << " " << back+1;
        }
        else
        {
            cout << "no";
        }
    }

    return 0;
}
