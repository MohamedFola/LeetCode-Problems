#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
    /*
        version 1: using equal_range built-in function
    */
    std::vector<int> searchRange_v1(std::vector<int>& nums, int target) {
        auto p = std::equal_range(nums.begin(), nums.end(), target);

        if(p.first != p.second)
            return {(int)(p.first - nums.begin()), (int)(p.second - nums.begin() - 1)};

        return {-1, -1};
    }

    /*
        version 2: using upper and lower bound built-in functions
    */
    std::vector<int> searchRange_v2(std::vector<int>& nums, int target) {
        std::vector<int>::iterator lower_it = std::lower_bound(nums.begin(), nums.end(), target);
        std::vector<int>::iterator upper_it = std::upper_bound(nums.begin(), nums.end(), target);

        std::vector<int> res = {-1, -1};

        if(upper_it != lower_it)
            res = {(int)(lower_it - nums.begin()), (int)(upper_it - nums.begin() - 1)};

        return res;
    }

    
    /*
        version 3: using binary search
    */
    int BSfindStart(std::vector<int> &nums, int target)
    {
        int position = -1;
        int start = 0, end = (int)nums.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] < target)
                start = mid + 1;
            else if(nums[mid] > target)
                end = mid - 1;
            else
                end = mid - 1, position = mid;
            
        }

        return position;
    }
    
    int BSfindEnd(std::vector<int> &nums, int target)
    {
        int position = -1;
        int start = 0, end = (int)nums.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] < target)
                start = mid + 1;
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1, position = mid;
            
        }

        return position;
    }

    std::vector<int> searchRange_v3(std::vector<int>& nums, int target) {
        return {BSfindStart(nums, target), BSfindEnd(nums, target)};
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {5,7,7,8,8,10};
    std::cout << "Using Version 1: ";
    for(auto const& element:(s.searchRange_v1(v, 8))) // 3  4
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 2: ";
    for(auto const& element:(s.searchRange_v2(v, 8))) // 3  4
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 3: ";
    for(auto const& element:(s.searchRange_v3(v, 8))) // 3  4
        std::cout << element << "  ";
    std::cout << std::endl << std::endl;


    std::cout << "Using Version 1: ";
    for(auto const& element:(s.searchRange_v1(v, 6))) // -1  -1
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 2: ";
    for(auto const& element:(s.searchRange_v2(v, 6))) // -1  -1
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 3: ";
    for(auto const& element:(s.searchRange_v3(v, 6))) // -1  -1
        std::cout << element << "  ";
    std::cout << std::endl << std::endl;


    std::cout << "Using Version 1: ";
    for(auto const& element:(s.searchRange_v1(v, 10))) // 5  5
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 2: ";
    for(auto const& element:(s.searchRange_v2(v, 10))) // 5  5
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 3: ";
    for(auto const& element:(s.searchRange_v3(v, 10))) // 5  5
        std::cout << element << "  ";
    std::cout << std::endl << std::endl;


    std::cout << "Using Version 1: ";
    for(auto const& element:(s.searchRange_v1(v, 5))) // 0  0
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 2: ";
    for(auto const& element:(s.searchRange_v2(v, 5))) // 0  0
        std::cout << element << "  ";
    std::cout << std::endl;

    std::cout << "Using Version 3: ";
    for(auto const& element:(s.searchRange_v3(v, 5))) // 0  0
        std::cout << element << "  ";
    std::cout << std::endl << std::endl;


    
    v = {};
    std::cout << "Using Version 1: ";
    for(auto const& element:(s.searchRange_v1(v, 0))) // -1  -1
    std::cout << element << "  ";
    std::cout << std::endl;
    
    std::cout << "Using Version 2: ";
    for(auto const& element:(s.searchRange_v2(v, 0))) // -1  -1
    std::cout << element << "  ";
    std::cout << std::endl;
    
    std::cout << "Using Version 3: ";
    for(auto const& element:(s.searchRange_v3(v, 0))) // -1  -1
    std::cout << element << "  ";
    std::cout << std::endl << std::endl;

    
    return 0;
}