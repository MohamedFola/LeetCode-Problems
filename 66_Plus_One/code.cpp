#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size() - 1;

        while (1)
        {
            if( digits[pos] < 9 ) 
            {
                digits[pos]++;
                break;
            }
            else
            {
                if(pos == 0 && digits[pos] == 9) 
                {
                    digits[pos] = 0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
                else
                {
                    digits[pos] = 0;
                    pos--;
                }
                
            }
        }
        
        return digits;
    }
};

int main()
{
    vector<int> v = {8, 9, 9};
    Solution s;


    v = s.plusOne(v);

    for (auto it : v)
    {
        cout << it << "  " << endl;
    }
    

    return 0;
}