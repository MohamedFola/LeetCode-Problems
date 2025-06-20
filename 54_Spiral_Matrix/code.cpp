#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        std::vector<int> result;

        int right = matrix[0].size() - 1;
        int left = 0;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (left <= right && top <= bottom)
        {
            // go from left to right
            for (int i = left; i <= right ; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;

            if (top > bottom) break;

            // go from top to bottom
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (left > right) break;

            // go from right to left
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;

            // go from bottom to top
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }

        return result;
    }
};


int main()
{
    Solution s;

    /**********************************************************************/
    // testing matrix nxn
    std::vector<std::vector<int>> input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    std::vector<int> result = s.spiralOrder(input);
    
    for(auto const& i:result)
    std::cout << i << "  ";
    
    std::cout << std::endl;

    // expected output -> 1 2 3 6 9 8 7 4 5
    
    
    /**********************************************************************/
    // testing matrix nxm where m > n
    input = {
        {1, 2 ,3},
        {4, 5, 6},
    };


    result = s.spiralOrder(input);

    for(auto const& i:result)
        std::cout << i << "  ";

    std::cout << std::endl;

    // expected output -> 1 2 3 6 5 4

    
    /**********************************************************************/
    // testing matrix nxm where n > m
    input = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
    };

    result = s.spiralOrder(input);

    for(auto const& i:result)
        std::cout << i << "  ";

    std::cout << std::endl;

    // expected output -> 1 2 4 6 8 10 12 11 9 7 5 3

    
    /**********************************************************************/
    // testing matrix 1xm
    input = {
        {1, 2, 3, 4},
    };


    result = s.spiralOrder(input);

    for(auto const& i:result)
        std::cout << i << "  ";

    std::cout << std::endl;

    // expected output -> 1 2 3 4

    
    /**********************************************************************/
    // testing matrix nx1
    input = {
        {1},
        {2},
        {3},
        {4},
        {5},
    };


    result = s.spiralOrder(input);

    for(auto const& i:result)
        std::cout << i << "  ";

    std::cout << std::endl;

    // expected output -> 1 2 3 4 5


    return 0;
}