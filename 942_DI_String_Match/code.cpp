#include<iostream>
#include<vector>

using namespace std;

/*
I -> for increment 
    start with 0 and increment it if I is found

D -> for decrement
    start with n and decrement it if D is found


example1:
s = "IDI"

    last = s.size() = 3
    first = 0

    first loop:
    I -> push first and increment it
    prem = 0 
    last = 3
    first = 1


    second loop:
    D -> push first and decrement it
    prem = 0 3
    last = 2
    first = 1


    third loop:
    I -> push first and increment it
    prem = 0 3 1
    last = 2
    first = 2

    then push last or first
    prem = 0 3 1 2


example 2:
s = "ID"

    last = s.size() = 2
    first = 0

    first loop:
    I ->push first and increment it
    prem = 0
    last = 2
    first = 1

    second loop:
    D -> push first and decrement it
    prem = 0 2
    last = 1
    first = 1

    then push last or first 
    prem = 0 2 1

*/

class Solution {
public:
    /*****************************
    *    runtime = 4ms           *
    *    memory = 10.23 MB       *
    *****************************/
    vector<int> diStringMatch(string s) {
        vector<int> prem;
        int last = s.size(), first = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                prem.push_back(first++);
            }
            else if(s[i] == 'D')
            {
                prem.push_back(last--);
            }
        }

        prem.push_back(last);

        return prem;
    }
};

int main()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    Solution s;
    std::string u1 = "IDID";
    std::string u2 = "ID" ;
    std::string u3 = "DID";

    v1 = s.diStringMatch(u1);
    v2 = s.diStringMatch(u2);
    v3 = s.diStringMatch(u3);

    for (auto vv:v1) { cout << vv << "  "; }
    std::cout << std::endl;
    
    for (auto vv:v2) { cout << vv << "  "; }
    std::cout << std::endl;

    for (auto vv:v3) { cout << vv << "  "; }
    std::cout << std::endl;


    return 0;
}