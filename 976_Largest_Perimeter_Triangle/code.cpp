#include<iostream>
#include<algorithm> // for using sort function
#include<vector>


class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) 
    {
        // sort the array
        std::sort(nums.begin(), nums.end()); // O(nLog(n))

        // check for this formula -> nums[i] < nums[i - 1] + nums[i - 2]
        // if this formula is right then the three sides can form a triangle
        // sorting will ensure that the largest three sides can form a triangle
        for(int i = (nums.size() - 3); i >= 0; i--) // O(n)
            if(nums[i + 2] < (nums[i + 1] + nums[i]))
                return nums[i] + nums[i + 1] + nums[i + 2];

        // no valid triangle is found
        return 0;
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {1, 20, 90, 43, 32};

    std::cout << s.largestPerimeter(v) << std::endl;
    
    return 0;
}