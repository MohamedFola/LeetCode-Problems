#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    /**************************************************************************************************************************************
    * in this approach we assemble all column char into one variable and check if this variable is sorted or not using is_sorted function *
    * runtime: 522ms                                                                                                                      *
    * memory: 506.69 MB                                                                                                                   *
    **************************************************************************************************************************************/
    int minDeletionSize1(vector<std::string>& strs) {
        int res = 0;
        for (size_t i=0; i<strs[0].size(); i++)
        {
            std::string tmp = "";

            for (std::string vv:strs)
            {
                tmp.push_back(vv[i]);
            }
            
            if(!is_sorted(tmp.begin(), tmp.end()))
                { res++; }
        }

        return res;
    }


    /*****************************
    *    runtime = 33ms          *
    *    memory = 14.12 MB       *
    *****************************/
    int minDeletionSize2(vector<std::string>& strs) {
        int res = 0;
        
        for (size_t col = 0; col < strs[0].size(); col++)
        {
            for (size_t row = 0; row < strs.size() - 1; row++)
            {
                if (strs[row][col] > strs[row+1][col])
                {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};

int main()
{
    vector<std::string> v = {"cba","daf","ghi"};
    vector<std::string> v1 = {"a","b"};
    vector<std::string> v2 = {"cba","daf","ghi","zyx","wvu","tsr"};
    vector<std::string> v3 = {"zyx","wvu","tsr"};
    
    Solution s;

    std::cout << s.minDeletionSize1(v) << "     ";
    std::cout << s.minDeletionSize2(v) << std::endl;
    std::cout << "***************************" << "\n\n";

    std::cout << s.minDeletionSize1(v1) << "     ";
    std::cout << s.minDeletionSize2(v1) << std::endl;
    std::cout << "***************************" << "\n\n";

    std::cout << s.minDeletionSize1(v2) << "     ";
    std::cout << s.minDeletionSize2(v2) << std::endl;
    std::cout << "***************************" << "\n\n";

    std::cout << s.minDeletionSize1(v3) << "     ";
    std::cout << s.minDeletionSize2(v3) << std::endl;
    std::cout << "***************************" << "\n\n";

    return 0;
}