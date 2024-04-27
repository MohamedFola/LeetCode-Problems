#include<iostream>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:

    /************************
    *    Map approach       *
    *    runtime = 252ms    *
    *    memory = 87.97 MB  *
    ************************/  
    int findDuplicate1(vector<int>& nums) {
        map<int, int> m;
        int repeated = 0;

        for (auto it:nums)
        {
            m[it]++;
            if (m[it] > 1) 
            {
                repeated = it;
                break;
            }
        }

        return repeated;
    }


    /********************************
    *    Binary Search approach     *
    *    runtime = 91ms             *
    *    memory = 63.57 MB          *
    ********************************/
    int findDuplicate2(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (int i:nums)
            {
                if (i <= mid) { count++; }
            }

            if (count > mid) right = mid;
            else left = mid + 1;
        }

        return left;   
    }

    /********************************
    *    Floyed's Algo approach     *
    *    runtime = 75ms             *
    *    memory = 63.68 MB          *
    ********************************/
    int findDuplicate3(vector<int>& nums) {
        int slow, fast;
        slow = fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }

};



int main()
{
    vector<int> v = {3,2,1,3};

    Solution s;

    cout << s.findDuplicate1(v) << endl;
    cout << s.findDuplicate2(v) << endl;
    cout << s.findDuplicate3(v) << endl;

    return 0;
}