#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int R, C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++)
        {
           cin >> G[G_i];
        }

        int r, c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++)
        {
           cin >> P[P_i];
        }

        int G_i = 0;
        int P_i = 0;
        vector<int> found(r, -1);
            
        while (G_i < R - r)
        {
            int i = G_i;
            while (P_i < r && i < r)
            {
                found[P_i] = G[i + P_i].find(P[P_i], found[P_i] + 1);
                if (found[P_i] != string::npos && ( P_i == 0 || found[P_i] == found[P_i-1]))
                {
                    P_i++;
                }
                else
                {
                    P_i = 0;
                }
            }

            /*cout << G_i << " " << P_i << " " << endl;
            for (int i = 0; i < r; i++)
                cout << found[i] << " " ;
            cout << endl;*/
            G_i++;
        }



        if (P_i == r)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
