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

        while(left <= right && top <= bottom)
        {
            // go from left to right
            for (int i = left; i <= right ; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;

            // go from top to bottom
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;

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

    std::vector<std::vector<int>> input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<int> result = s.spiralOrder(input);

    for(auto const& i:result)
        std::cout << i << "  ";

    std::cout << std::endl;

    return 0;
}