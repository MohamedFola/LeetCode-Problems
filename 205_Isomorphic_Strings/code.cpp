#include<iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char chr[256] = {0};
        bool mapped[256] = {false};


        if (s.size() != t.size()) return false;

        for (size_t i = 0; i < s.size(); i++) 
        {
            if (chr[s[i]] == 0)
            {
                if (mapped[t[i]] == false )
                {
                    chr[s[i]] = t[i];
                    mapped[t[i]] = true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (mapped[t[i]] == false) return false;
                else if(chr[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    string f, l;

    cin >> f >> l;

    cout << s.isIsomorphic(f, l) << endl;

    return 0;
}