#include <iostream>
using namespace std;

int main()
{
    int n, k, a, count = 0;
    cin >> n >> k;
    for ( int i = 0; i < n; i++ )
    {
        cin >> a;
        count += ( a%k == 0 );
    }
    cout << count;
    return 0;
}