#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        sort(strs.begin(), strs.end());
        string first_element = strs[0], last_element = strs[strs.size() - 1];
        for(int i = 0 ; i < min(first_element.size(), last_element.size()) ; i++)
        {
            if( first_element[i] != last_element[i] ) return res;
            res += first_element[i];
        }

        return res;        
    }
};


int main()
{
    vector<string>v = {"flower","flow","flight"};

    Solution s;

    cout << s.longestCommonPrefix(v);

    return 0;
}

