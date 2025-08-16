#include<iostream>
#include<vector>

class Solution
{
private:

    // helper functions for version 1
    bool find_element(std::vector<int>& nums, int target)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
                return true;
        }

        return false;
    }

    // helper functions for version 2

    /*  this function returns the number of missing elements between the element of index 0 and element of index k
        for example: nums =    [1,4,9,12]
                     missing = [0,2,6,8]
        - how we got this?? for element 9 its index is 2 so we expected that there are (9 - 1 - 1 = 7) elements between them
            but we acctually have only 1 element as the first element is at index 0 and 9 is at index 2 so we have only one element at index 1
            so by subtarcting 9 and the first element we got the elements in between, then by subtracting the index of 9 we got the missing elements
            9 - nums[0] - (index of 9) = missing element between 9 and first element
    */
    int missing(std::vector<int>& nums, int k)
    {
        return nums[k] - nums[0] - k;
    }

public:
    int missingElement_v1(std::vector<int>& nums, int k)
    {
        int res = 0;

        int target = nums[0] + 1;
        while(k)
        {
            if(!find_element(nums, target))
            {
                k--;
                res = target;
            }
            target++;
        }

        return res;
    }

    /*
        - example to get the solution, nums = [1,4,9,12] and k = 3
        - missing element numbers(we already discussed why in missing function) = [0,2,6,8] this is a monotonic increasing
        - when we search for k = 3 we will get index 2 which is 6
        - now we use element at index - 1 which is 4 to be the start of our search as now we know that the target value lies between index 2 and 1
        - 4 + 3 - 2(missing element between 4 and 1) = 5

        - what if the missing element is beyond nums?? -> this is a special case that should be handled
        - example: nums = [1,2,4] and k = 3
        - missing elements = [0,0,1] then k is larger than the missing elements in the array
        - solution should be last element + k - 1
    */
    int missingElement_v2(std::vector<int>& nums, int k)
    {
        int nums_size = nums.size() - 1;
        int lower_bound = -1, start = 0, end = nums.size() - 1;

        // handling special case when k is larger than the missing elements
        if(k > missing(nums, nums_size))
            return nums[nums_size] + (k - missing(nums, nums_size));

        // do a binary search to get the first element that is >= kth
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if(missing(nums, mid) >= k)
                end = mid - 1, lower_bound = mid;
            else
                start = mid + 1;
        }
        
        // (start of the search) + k - (the number of missing elements between start of the search and first element)
        return nums[lower_bound - 1] + (k - missing(nums, lower_bound - 1));
    }
};

int main()
{
    Solution s;
    std::vector<int> nums;
    int k;

    nums = {4, 7, 9, 10};
    k = 1;
    std::cout << "The Kth missing element using version 1 is " << s.missingElement_v1(nums, k) << std::endl; // 5
    std::cout << "The Kth missing element using version 2 is " << s.missingElement_v2(nums, k) << std::endl << std::endl; // 5

    nums = {4, 7, 9, 10};
    k = 3;
    std::cout << "The Kth missing element using version 1 is " << s.missingElement_v1(nums, k) << std::endl; // 8
    std::cout << "The Kth missing element using version 2 is " << s.missingElement_v2(nums, k) << std::endl << std::endl; // 8

    nums = {1, 2, 4};
    k = 3;
    std::cout << "The Kth missing element using version 1 is " << s.missingElement_v1(nums, k) << std::endl; // 6
    std::cout << "The Kth missing element using version 2 is " << s.missingElement_v2(nums, k) << std::endl << std::endl; // 6

    nums = {1, 4};
    k = 3;
    std::cout << "The Kth missing element using version 1 is " << s.missingElement_v1(nums, k) << std::endl; // 5
    std::cout << "The Kth missing element using version 2 is " << s.missingElement_v2(nums, k) << std::endl << std::endl; // 5
    
    return 0;
}