#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
    int reductionOperations_v1(std::vector<int>& nums) 
    {
        int operations = 0;
        int nums_size = nums.size();

        std::sort(nums.rbegin(), nums.rend());

        for(int i = 1; i < nums_size; i++)
            if(nums[i] != nums[i - 1])
                operations += i;

        return operations;
    }

    int reductionOperations_v2(std::vector<int>& nums) 
    {
        int operations = 0;
        int nums_size = nums.size();

        std::sort(nums.begin(), nums.end());

        int increment = 0;
        for(int i = 1; i < nums_size; i++)
        {
            if(nums[i] != nums[i - 1])
                increment++;
        
            operations += increment;
        }

        return operations;
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {5,1,3};
    std::cout << "Number of operations: " << s.reductionOperations_v1(v) << "\n"; // 3
    v = {5,1,3};
    std::cout << "Number of operations: " << s.reductionOperations_v2(v) << "\n"; // 3

    v = {1,1,1};
    std::cout << "Number of operations: " << s.reductionOperations_v1(v) << "\n"; // 0
    v = {1,1,1};
    std::cout << "Number of operations: " << s.reductionOperations_v2(v) << "\n"; // 0

    v = {1,1,2,2,3};
    std::cout << "Number of operations: " << s.reductionOperations_v1(v) << "\n"; // 4
    v = {1,1,2,2,3};
    std::cout << "Number of operations: " << s.reductionOperations_v2(v) << "\n"; // 4
    
    return 0;
}