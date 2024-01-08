#include<iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int f = 0, s = 0, carry = 0;
        string result = "";

        while( !a.empty() || !b.empty() )
        {
            if(!a.empty())
            {
                f = a[a.size() - 1] - '0';
                a.pop_back();
            }

            if(!b.empty())
            {
                s = b[b.size() - 1] - '0';
                b.pop_back();
            }

            if ( f + s + carry == 2 )
            {
                result += "0";
                carry = 1;
            }
            else if ( f + s + carry == 3 )
            {
                result += "1";
                carry = 1;
            }
            else
            {
                result += to_string(f + s + carry);
                carry = 0;
            }

            f = s = 0;
        }

        return result;
    }
};

int main()
{

    return 0;
}