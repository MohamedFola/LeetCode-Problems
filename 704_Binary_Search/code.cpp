#include<iostream>
#include<vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;

        while(left <= right)
        {
            int mid = left + ((right - left) / 2);

            if(nums[mid] == target) 
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {3, 6, 86, 209, 555, 678};

    std::cout << "index of 3 is " << s.search(v, 3) << "\n";
    std::cout << "index of 6 is " << s.search(v, 6) << "\n";
    std::cout << "index of 86 is " << s.search(v, 86) << "\n";
    std::cout << "index of 209 is " << s.search(v, 209) << "\n";
    std::cout << "index of 555 is " << s.search(v, 555) << "\n";
    std::cout << "index of 678 is " << s.search(v, 678) << "\n";
    std::cout << "index of 5 is " << s.search(v, 5) << "\n";
    std::cout << "index of 10 is " << s.search(v, 10) << "\n";
    std::cout << "index of 5784 is " << s.search(v, 5784) << "\n";

    return 0;
}