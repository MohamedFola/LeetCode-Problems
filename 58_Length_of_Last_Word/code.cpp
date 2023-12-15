#include<iostream>
#include<vector>

using namespace std;

// not the best solution but it works
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         vector<string>words;
//         string word = "";
//         for ( char c:s )
//         {
//             if( c == ' ' )
//             {
//                 if ( word.size() != 0 ) words.push_back(word);
//                 word = "";
//             }
//             else
//             {
//                 word += c;
//             }
            
//         }

//         if ( word.size() != 0 ) words.push_back(word);

//         for ( auto temp:words ) cout << temp << endl;
        
//         return words[words.size() - 1].size();
        
//     }
// };


// better solution
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int length = 0, flag = 0;
        for ( int i = s.size() - 1; i >= 0; i-- )
        {
            if ( s[i] != ' ' ) 
            {
                length++;
                flag = 1;
            }
            else if( s[i] == ' ' && flag == 1 ) break;
        }

        return length;
    }

};

int main()
{
    Solution s;
    string r = "Hello World";

    cout << s.lengthOfLastWord(r);

    return 0;
}