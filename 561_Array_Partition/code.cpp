#include<iostream>
#include<algorithm> // for using sort function
#include<vector>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        // sort the array
        std::sort(nums.begin(), nums.end());

        int result = nums[0];

        for(int i = 2; i < nums.size(); i+=2)
            result += nums[i];
        
        return result;
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {1,4,3,2};
    std::cout << s.arrayPairSum(v) << std::endl;

    v = {6,2,6,5,1,2};
    std::cout << s.arrayPairSum(v) << std::endl;

    return 0;
}