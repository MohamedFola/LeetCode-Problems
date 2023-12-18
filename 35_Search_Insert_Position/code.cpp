#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;

        if ( target > nums[right] ) return right;

        while ( left <= right )
        {
            mid = left + (( right - left ) / 2);
            
            if (nums[mid] == target)
                return mid;

            if ( nums[mid] < target )
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};

int main()
{
    vector<int> v = {1,2,3,4};

    Solution s;

    cout << s.searchInsert(v, 3);

    return 0;
}