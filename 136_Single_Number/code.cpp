#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    /************************
    *    Map approach       *
    *    runtime = 29ms     *
    *    memory = 23.03 MB  *
    ************************/
    int singleNumber1(vector<int>& nums) {
        int result = nums[0];
        map<int, int> m;

        if (nums.size() == 1) return result;
        
        for (auto it:nums) { m[it]++; }

        for (auto it:m) 
        {
            if (it.second < 2) { result = it.first; }
        }

        return result;
    }

    /*************************************
    *    Bit manipulation approach       *
    *    runtime = 11ms                  *
    *    memory = 19.33 MB               *
    *************************************/
    int singleNumber2(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) { result ^= nums[i]; }
        
        return result;
    }
};

int main()
{
    vector<int> v = {2,2,3,6,3};

    Solution s;

    cout << s.singleNumber1(v) << endl;
    cout << s.singleNumber2(v) << endl;

    return 0;
}