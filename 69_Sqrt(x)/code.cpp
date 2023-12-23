#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;

        while ( start < end )
        {
            long mid = start + ( end - start ) / 2;
            if ( ( mid * mid ) == x ) return mid;
            else if ( ( mid * mid ) > x ) end = mid -1 ;
            else start = mid + 1;
            
        }

        return end;
        
    }
};

int main()
{
    Solution s;
    int x;

    cin >> x;

    cout << s.mySqrt(x) << endl;

    return 0;
}  