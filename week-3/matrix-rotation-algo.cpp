#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int m, n, r;
    cin >> m >> n >> r;

    int n_layers = min(m,n)/2;

    vector < vector<int> > matrix (m, vector<int>(n));
    vector < vector<int> > layers (n_layers);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    for (int cur_layer = 0; cur_layer < n_layers; cur_layer++)
    {
        int i, j;

        // Separate the matrix into layers
        j = cur_layer;
        for (i = cur_layer; i < (m-cur_layer); i++)
        {
            layers[cur_layer].push_back(matrix[i][j]);
        }

        i = m-cur_layer-1;
        for (j = cur_layer+1; j < (n-cur_layer); j++)
        {
            layers[cur_layer].push_back(matrix[i][j]);
        }

        j = n-cur_layer-1;
        for (i = m-cur_layer-2; i > cur_layer-1; i--)
        {
            layers[cur_layer].push_back(matrix[i][j]);            
        }

        i = cur_layer;
        for (j = n-cur_layer-2; j > cur_layer; j--)
        {
            layers[cur_layer].push_back(matrix[i][j]);
        }

        //Rotate the layers
        rotate( layers[cur_layer].rbegin(), 
                layers[cur_layer].rbegin() + (r%layers[cur_layer].size()), 
                layers[cur_layer].rend() );
        
        //Put the matrix back together
        int count = 0;
        j = cur_layer;
        for (i = cur_layer; i < (m-cur_layer); i++)
        {
            matrix[i][j] = layers[cur_layer][count++];
        }

        i = m-cur_layer-1;
        for (j = cur_layer+1; j < (n-cur_layer); j++)
        {
            matrix[i][j] = layers[cur_layer][count++];
        }

        j = n-cur_layer-1;
        for (i = m-cur_layer-2; i > cur_layer-1; i--)
        {
            matrix[i][j] = layers[cur_layer][count++];
        }

        i = cur_layer;
        for (j = n-cur_layer-2; j > cur_layer; j--)
        {
            matrix[i][j] = layers[cur_layer][count++];
        }

    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
