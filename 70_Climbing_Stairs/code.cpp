#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if ( n == 0 || n == 1 ) return 1;

        int temp, prev = 1;
        int result = 2;

        for ( int i = 2; i < n; i++ )
        {
            temp = result;
            result = result + prev;
            prev = temp;
        }

        return result;
    }
};

int main()
{
    Solution s;
    int num;

    while ( num != 0 )
    {
        cin >> num;
        cout << s.climbStairs(num) << endl;
    }
    

    
    return 0;
}