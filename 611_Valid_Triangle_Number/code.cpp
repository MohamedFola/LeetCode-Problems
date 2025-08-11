#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
private:
    int BSFindFirst(std::vector<int> &nums, int start, int target)
    {
        int end = (int)nums.size() - 1, position = nums.size();

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(target <= nums[mid])
                end = mid - 1, position = mid;
            else if(target > nums[mid])
                start = mid + 1;
        }
        
        return position;
    }
public:
    int triangleNumber_1(std::vector<int>& nums) {
        int res = 0;
        int nums_size = nums.size();

        std::sort(nums.begin(), nums.end());

        for(int first_side = 0; first_side < nums_size - 2; first_side++)
        {
            for(int second_side = first_side + 1; (second_side < nums_size - 1) && (nums[first_side] != 0); second_side++)
            {
                int pos = BSFindFirst(nums, second_side + 1, nums[first_side] + nums[second_side]);

                res += pos - second_side - 1;
            }
        }
        return res;
    }

    
    int triangleNumber_2(std::vector<int>& nums) {
        int res = 0;
        int nums_size = nums.size();

        std::sort(nums.begin(), nums.end());

        for(int first_side = 0; (first_side < nums_size - 2); first_side++)
        {
            for(int second_side = first_side + 1; second_side < nums_size - 1 && (nums[first_side] != 0); second_side++)
            {
                int first_index = nums.size();
                std::vector<int>::iterator pos = std::lower_bound(nums.begin() + second_side + 1, nums.end(), nums[first_side] + nums[second_side]);

                if(pos != nums.end())
                    first_index = pos - nums.begin();
                res += first_index - second_side - 1;
            }
        }
        return res;
    }

    int triangleNumber_3(std::vector<int>& nums) {
        int res = 0;
        int nums_size = nums.size();

        std::sort(nums.begin(), nums.end());

        int third_side_pos;
        for(int first_side = 0; first_side < nums_size - 2; first_side++)
        {
            for(int second_side = first_side + 1; (second_side < nums_size - 1) && (nums[first_side] != 0); second_side++)
            {
                third_side_pos = second_side + 1;
                while((third_side_pos < nums_size) && (nums[first_side] + nums[second_side] > nums[third_side_pos]))
                    third_side_pos++;
                res += third_side_pos - second_side - 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::vector<int> v;

    v = {2,2,3,4};
    std::cout << "Version 1: " << s.triangleNumber_1(v) << std::endl; // 3
    v = {2,2,3,4};
    std::cout << "Version 2: " << s.triangleNumber_2(v) << std::endl; // 3
    v = {2,2,3,4};
    std::cout << "Version 2: " << s.triangleNumber_3(v) << std::endl; // 3
    std::cout << std::endl;

    v = {4,2,3,4};
    std::cout << "Version 1: " << s.triangleNumber_1(v) << std::endl; // 4
    v = {4,2,3,4};
    std::cout << "Version 2: " << s.triangleNumber_2(v) << std::endl; // 4
    v = {4,2,3,4};
    std::cout << "Version 2: " << s.triangleNumber_3(v) << std::endl; // 4
    std::cout << std::endl;

    v = {0, 5, 7, 2, 8, 2};
    std::cout << "Version 1: " << s.triangleNumber_1(v) << std::endl; // 3
    v = {0, 5, 7, 2, 8, 2};
    std::cout << "Version 2: " << s.triangleNumber_2(v) << std::endl; // 3
    v = {0, 5, 7, 2, 8, 2};
    std::cout << "Version 2: " << s.triangleNumber_3(v) << std::endl; // 3
    std::cout << std::endl;

    v = {1};
    std::cout << "Version 1: " << s.triangleNumber_1(v) << std::endl; // 0
    v = {1};
    std::cout << "Version 2: " << s.triangleNumber_2(v) << std::endl; // 0
    v = {1};
    std::cout << "Version 2: " << s.triangleNumber_3(v) << std::endl; // 0
    std::cout << std::endl;

    return 0;
}