// Calculate the number of trailing zeroes in a factorial
// of a given number n

#include<iostream>
using namespace std;
int trailing_zeroes(int n)
{
    int n_zeroes = 0;
    int temp = n;

    while (temp != 0)
    {
        n_zeroes += (temp/5);
        temp /= 5;
    }
    return n_zeroes;
}

int main()
{
    int t;
    int n;
    cin >> t;
    for ( int i = 0; i < t; i++)
    {
        cin >> n;
        cout << trailing_zeroes(n) << endl;
    }
    return 0;
}