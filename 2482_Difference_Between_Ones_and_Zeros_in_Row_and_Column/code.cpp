#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        vector<int>onesR(rows, 0);
        vector<int>onesC(cols, 0);

        vector<vector<int>>res(rows, onesC);

        for ( int i = 0; i < rows; i++  )
        {
            for ( int j = 0; j < cols; j++ )
            {
                onesR[i] += grid[i][j];
                onesC[j] += grid[i][j];
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res[i][j] = ( 2 * (onesC[j] + onesR[i]) ) - rows - cols;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>>v = {
        {0,1,1},
        {1,0,1},
        {0,0,1},
        };

    vector<vector<int>>r;
    r = s.onesMinusZeros(v);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}

/*
i = 0 , j = 0 

*/