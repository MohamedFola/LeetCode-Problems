#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        int max_sum = 0;
        
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                if(i == 0)
                {
                    max_sum = nums[i];
                }
                else
                {
                    if(nums[i] != nums[i-1])
                    {
                        max_sum += nums[i];
                    }
                }
            }
            else if((nums[i] < 0) && (i == (nums.size() - 1)))
            {
                max_sum += nums[i];
            }
        }

        return max_sum;
    }
};

int main()
{
    Solution s;

    std::vector<int> v;

    v = {1,2,3,4,5};
    std::cout << s.maxSum(v) << std::endl; // 15

    v = {1,1,0,1,1};
    std::cout << s.maxSum(v) << std::endl; // 1
    
    v = {1,2,-1,-2,1,0,-1};
    std::cout << s.maxSum(v) << std::endl; // 3
    
    v = {-100,-90};
    std::cout << s.maxSum(v) << std::endl; // 3
    
    v = {0};
    std::cout << s.maxSum(v) << std::endl; // 3

    return 0;
}