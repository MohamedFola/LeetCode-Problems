# 856. Score of Parentheses 
## 📚 Table of Contents
- [Requirements of the Problem](#requirements)
- [Examples](#example)
- [Solution Illustration](#solution)
- [Code](#code)

### **Requirements of the Problem**
Given a balanced parentheses string s, return the ***score*** of the string.
The score of a balanced parentheses string is based on the following rule:
- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.
### **Examples**
Example 1:

    Input: s = "()"
    Output: 1
Example 2:

    Input: s = "(())"
    Output: 2
Example 3:

    Input: s = "()()"
    Output: 2


### **Solution Illustration**
**Key Concepts:**

- When you encounter a (, it indicates a new sub-expression is starting.
- When you encounter a ), it indicates the end of a sub-expression, so you need to calculate the score for the current sub-expression.

The algorithm uses a stack to handle the nested structure of parentheses.

**Explanation:**
1) ***Initialization:***

- We use a stack `stc` to store intermediate scores.
- The variable `score` is used to calculate the score at each level of parentheses nesting.

2) ***Iterating through the string:***

- The loop goes through each character `c` in the string `s`.

3) ***When encountering `(`:***

- When we see an opening parenthesis `'('`, we push the current `score` onto the stack. This is because we are entering a new level of nesting, and the score at the current level is saved so that we can add to it later.
- After pushing the current `score`, we reset `score` to `0` because we are starting a new sub-expression (inside the parentheses).
    ```cpp
    stc.push(score);
    score = 0;
    ```
4) ***When encountering ` )`:***

- When we see a closing parenthesis `')'`, it means we are closing a sub-expression.
- At this point, we compute the score for the sub-expression we just closed:
    - If the sub-expression is `()`, its `score` is `1`. This happens when `score` is still `0`, so we use `std::max(score * 2, 1)` to ensure that the minimum `score` is `1`.
    - Otherwise, the score is `2 * score`, because we are multiplying the score of the inner expression by 2 (following the problem rule).
- After calculating the score for the current sub-expression, we add it to the score saved in the stack (from the previous level), and then pop the stack to return to the previous level of nesting.
    ```cpp
    score = stc.top() + std::max((score * 2), 1);
    stc.pop();
    ```
5) ***Return the final score:***

- After processing the entire string, `score` will contain the total score for the balanced parentheses string.


**Example Walkthrough:**

Let’s consider the string s = `"(()(()))"`:

1) **Initialization:**

    - `stc = []`, `score = 0`.

2) **First `(`:**

    - We encounter `'('`, push `score` (which is 0) onto the stack.
    - `stc = [0]`, `score = 0`.

3) **Second `(`:**

    - We encounter another `'('`, push `score` (which is 0) onto the stack.
    - `stc = [0, 0]`, `score = 0`.

4) **First `)`:**

    - We encounter `')'`, compute `score = 0 + max(0 * 2, 1) = 1`.
    - Pop the stack (`stc = [0]`).
    - Now, `score` = 1.

5) **Third `(`:**

    - We encounter `'('`, push `score` (which is 1) onto the stack.
    - `stc = [0, 1]`, `score = 0`.

6) **Fourth `(`:**

    - We encounter another `'('`, push `score` (which is 0) onto the stack.
    - `stc = [0, 1, 0]`, `score = 0`.

7) **Second `)`:**

    - We encounter `')'`, compute `score = 0 + max(0 * 2, 1) = 1`.
    - Pop the stack (`stc = [0, 1]`).
    - Now, `score = 1`.

8) **Third `)`:**

    - We encounter `')'`, compute `score = 1 + max(1 * 2, 1) = 3`.
    - Pop the stack (`stc = [0]`).
    - Now, `score = 3`.

9) **Fourth `)`:**

    - We encounter `')'`, compute `score = 0 + max(3 * 2, 1) = 6`.
    - Pop the stack (`stc = []`).
    - Now, `score = 6`.

**Final result: `score = 6`.**



### **Code**
```cpp
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
```