#include<iostream>
#include<stack>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        std::stack<int> stc;
        int score = 0;

        for (auto c:s)
        {
            if (c == '(')
            {
                stc.push(score);
                score = 0;
            }
            else // c == ')'
            {
                score = stc.top() + std::max((score * 2), 1);
                stc.pop();
            }
        }

        return score;
    }
};

int main()
{
    Solution sol;
    std::string s;

    std::cout << "Please enter the expression: ";
    std::cin >> s;

    std::cout << sol.scoreOfParentheses(s) << std::endl;

    return 0;
}