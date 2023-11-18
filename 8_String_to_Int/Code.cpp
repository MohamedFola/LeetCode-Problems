#include<iostream>
#include<math.h>
#include<string>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        double res = 0, sign = 1, i = 0;

        // read leading whitespaces
        while ( s[i] == ' ' ) i++;

        // read the sign
        if ( s[i] == '-' )
        {
            sign = -1;
            i++;
        }
        else if ( s[i] == '+' ) i++;
        
        // read until no digit is found
        while ( i < s.length() )
        {
            if ( s[i] >= '0' && s[i] <= '9' )
            {
                res = ( res * 10 ) + ( s[i++] - '0' );
            }
            else break;
        }

        // adjust the sign
        res *= sign;

        // check if the number is greater than 32 bits
        if( res > INT32_MAX ) res = INT32_MAX;
        if( res < INT32_MIN ) res = INT32_MIN;


        return res;
    }
};


int main()
{
    Solution s;
    string input;

    getline( cin, input );

    while ( input != "e" )
    {
        cout << s.myAtoi( input ) << endl;
        getline( cin, input );
    }
    

    return 0;
}