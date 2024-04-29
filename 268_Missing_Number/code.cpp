#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    /****************************
    *    Sorting approach       *
    *    runtime = 18ms         *
    *    memory = 20.99 MB      *
    ****************************/
    int missingNumber1(vector<int>& nums) {
        int iterator = 0, res = nums.size();
        sort(nums.begin(), nums.end());

        for (auto i:nums) 
        { 
            if (i != iterator) return iterator;
            iterator++;
        }

        return res;
    }

    /****************************
    *    Xoring approach        *
    *    runtime = 9ms          *
    *    memory = 20.2 MB       *
    ****************************/
    int missingNumber2(vector<int>& nums)
    {
        int res = 0;
        for (size_t i = 0; i <= nums.size(); i++){ res ^= i; }

        for (auto i:nums){ res ^= i; }

        return res;
    }

    /*****************************
    *    Summing approach        *
    *    runtime = 12ms          *
    *    memory = 20.39 MB       *
    *****************************/
    int missingNumber3(vector<int>& nums)
    {
        int sum = ((nums.size()) * (nums.size()+1)) / 2;

        return sum - accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{
    vector<int>v = {1,2};
    Solution s;

    cout << s.missingNumber1(v) << "\n";
    cout << s.missingNumber2(v) << "\n";
    cout << s.missingNumber3(v) << "\n";

    return 0;
}