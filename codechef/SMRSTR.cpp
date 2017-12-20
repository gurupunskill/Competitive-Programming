#include <iostream>
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, q;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;
        long long prod = 1, d;
        bool flag;
        for ( int i = 0; i < n; i++)
        {
            cin >> d;
            prod *= d; 
        }

        long long x;
        for ( int i = 0; i < q; i++)
        {
            cin >> x;
            cout << x/prod << " ";
        }
        cout << endl;
    }
    return 0;
}