// https://www.hackerrank.com/challenges/queens-attack-2/problem

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

#define all(a) a.begin(),a.end()

int main()
{    
    int n, k;
    cin >> n >> k;
    int rqueen, cqueen;
    cin >> rqueen >> cqueen;
 
    /*
    *   0 -> Same row, right side. [Xo = rqueen][Yo > cqueen]
    *   1 -> Same row, left side.  [Xo = rqueen][Yo < cqueen]
    *   2 -> Same column, above.   [Xo > rqueen][Yo = cqueen]
    *   3 -> Same column, below.   [Xo < rqueen][Yo = cqueen]
    *   Diagonal condition -> |Xo - rqueen| == |Yo - cqueen|
    *   4 -> Upper right diagonal. [Xo > rqueen][Yo > cqueen]  
    *   5 -> Upper left diagonal.  [Xo > rqueen][Yo < cqueen]
    *   6 -> Lower right diagonal. [Xo < rqueen][Yo > cqueen]
    *   7 -> Lower left diagonal.  [Xo < rqueen][Yo < cqueen]
    */
    
    vector <int> distances(8);

    distances[0] = n - cqueen;
    distances[1] = cqueen - 1;
    distances[2] = n - rqueen;
    distances[3] = rqueen - 1;

    distances[4] = min(n - rqueen, n - cqueen);
    distances[5] = min(n - rqueen, cqueen - 1);
    distances[6] = min(rqueen - 1, n - cqueen);
    distances[7] = min(rqueen - 1, cqueen - 1);
    
    /*for ( int i = 0; i < 8; i++ )
        cout << distances[i] << " ";
    cout << endl;
    */
    while(k--)
    {
        int Xo, Yo;
        cin >> Xo >> Yo;
        
        int dist = abs(Xo - rqueen) + abs(Yo - cqueen) - 1;
        if (Xo == rqueen)
        {
            if (Yo == cqueen)
                return 1;
            if (Yo > cqueen)
            {
                distances[0] = min(distances[0], dist);
            }

            if (Yo < cqueen)
            {
                distances[1] = min(distances[1], dist);                
            }
        }

        else if (Yo == cqueen)
        {
            if (Xo > rqueen)
            {
                distances[2] = min(distances[2], dist);
            }
            if (Xo < rqueen)
            {
                distances[3] = min(distances[3], dist);
            }
        }

        else if ( abs(Xo-rqueen) == abs(Yo-cqueen) )
        {
            dist = abs(Xo - rqueen) - 1;            
            if (Xo > rqueen)
            {
                if (Yo > cqueen)
                {
                    distances[4] = min(distances[4], dist);                    
                }
                if (Yo < cqueen)
                {
                    distances[5] = min(distances[5], dist);                    
                }
            }
            if (Xo < rqueen)
            {
                if (Yo > cqueen)
                {
                    distances[6] = min(distances[6], dist);                    
                }
                if (Yo < cqueen)
                {
                    distances[7] = min(distances[7], dist);                    
                }
            }
        }
        /*for ( int i = 0; i < 8; i++ )
            cout << distances[i] << " ";
        cout << endl;*/
    }

    cout << accumulate(all(distances), 0);    
    return 0;
}
