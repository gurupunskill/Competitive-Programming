#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        //char R[N][M], G[N][M], C[N][M];
        char C;
        int costG = 0, costR = 0;
        char A[2] = {'R', 'G'};
        //int costs[2] = {3, 5};
        for ( int i = 0; i < N; i++ )
        {
            for ( int j = 0; j < M; j++ )
            {
                //R[i][j] = A[(i+j)%2];
                //G[i][j] = A[!((i+j)%2)];
                cin >> C;
                if(C == A[(i+j)%2])
                {
                    if (C == 'R')
                        costG += 5;
                    else
                        costG += 3;
                }
                else
                {
                    if (C == 'R')
                        costR += 5;
                    else
                        costR += 3;
                }
            }
        }
        cout << min(costG, costR);    
    }
}