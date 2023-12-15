#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        if ( s.size() == 0 )  return false;

        for ( char c:s )
        {
            if ( c == '[' || c == '(' || c == '{' ) st.push( c );
            else 
            {
                if ( ( st.empty() ) || 
                     ( c == ']' && st.top() != '[' ) || 
                     ( c == ')' && st.top() != '(' ) || 
                     ( c == '}' && st.top() != '{' ) ) 
                     return false;
                st.pop();
            }
        }

        if ( st.empty() ) return true;
        else return false;
    }
};

int main()
{
    Solution res;
    string s;

    cin >> s;

    if ( res.isValid( s ) ) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}