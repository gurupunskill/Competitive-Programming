#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        bool flag = true;
        vector<int> perms(n, 1);

        for (int i = 1; i <= n; i++)
        {
            int value = i - k;
            if (value < 1 || perms[value-1] < 0)
            {
                value = i + k;
                if (value > n || perms[value-1] < 0)
                {
                    flag = false;
                    break;
                }
            }
            perms[i-1] *= value;
            perms[value - 1] *= -1;
        }

        if (flag)
        {
            for (int i = 0; i < n; i++)
                cout << abs(perms[i]) << " ";
            cout << endl;
        }
        else cout << -1 << endl;

    }
    return 0;
}
