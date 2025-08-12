#include<iostream>
#include<vector>

class Solution {
private:
    bool possible(std::vector<int>& nums, int threshold, int divisor)
    {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += (nums[i] + divisor - 1) / divisor; // ceil equation
        return sum <= threshold;
    }
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int max = INT_MIN;
        
        for(auto const& element:nums)
            if(element > max)
                max = element;
        
        int start = 1, end = max;
        int res = end;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(possible(nums, threshold, mid))
                res = mid, end = mid - 1;
            else
                start = mid + 1;
        }

        return res;
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {1,2,5,9};
    std::cout << s.smallestDivisor(v, 6) << std::endl;

    v = {44,22,33,11,1};
    std::cout << s.smallestDivisor(v, 5) << std::endl;

    v = {21212,10101,12121};
    std::cout << s.smallestDivisor(v, 1000000) << std::endl;
    
    return 0;
}