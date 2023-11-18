#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, index = 0;

        for ( auto it:nums )
        {
            if ( it != val )
            {
                nums[index++] = it;
            }
        }
        

        return index;
    }
};

int main()
{
    Solution s;

    vector<int>v;
    v.push_back(7);
    v.push_back(5);
    v.push_back(2);
    v.push_back(5);

    cout << s.removeElement(v, 5) << endl;



    return 0;
}