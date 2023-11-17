#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        string result;
        int direction = -1, iterator = 0;

        string results[ numRows ] = { "" };

        if ( numRows == 1 || numRows == 0 ) return s;

        for ( int i = 0; i < s.size(); i++ )
        {
            if ( ( iterator == numRows - 1 ) || ( iterator == 0 ) )
            {
                direction *= -1;
            }

            results[iterator] += s[ i ];

            if ( direction == 1 )
            {
                iterator++;
            }
            else
            {
                iterator--;
            }
        }

        for ( auto &it:results )
        {
            result += it;
        }
        
        return result;
    }
};

int main()
{
    string in;
    int rows;
    Solution s;

    cin >> in >> rows;

    cout << s.convert( in, rows );

    return 0;
}