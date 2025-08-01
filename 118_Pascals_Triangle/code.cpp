#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;
        
        res.push_back({1});
        
        for(int i = 1; i < numRows; i++)
        {
            std::vector<int> tmp;
            tmp.push_back(1);
            for(int j = 0; j < i - 1; j++)
                tmp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
            tmp.push_back(1);

            res.push_back(tmp);
        }

        return res;
    }
};

void print_vector(int numRows)
{
    Solution s;

    for(auto const& el:s.generate(numRows))
    {
        for(auto const& el2:el)
            std::cout << el2 << "  ";

        std::cout << std::endl;
    }

    std::cout << "\n\n";
}

int main()
{
    print_vector(1);
    print_vector(2);
    print_vector(3);
    print_vector(4);
    print_vector(5);
    print_vector(6);
    
    return 0;
}