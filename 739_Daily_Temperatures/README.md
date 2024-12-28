# 739. Daily Temperatures
## 📚 Table of Contents
- [Requirements of the Problem](#requirements)
- [Examples](#example)
- [Solution Illustration](#solution)
- [Code](#code)

### **Requirements of the Problem**
Given an array of integers `temperatures` represents the daily temperatures, return *an array* `answer` such that `answer[i]` *is the number of days you have to wait after the `ith` day to get a warmer temperature*. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

### **Examples**
**Example 1:**

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

**Example 2:**

    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

**Example 3:**

    Input: temperatures = [30,60,90]
    Output: [1,1,0]

### **Solution Illustration**

**Algorithm Explanation:**

The key idea is to use a **monotonic decreasing stack** to efficiently keep track of the indices of temperatures as we iterate through the input. The stack helps us quickly find the next warmer temperature for each day.

**Steps of the Algorithm:**

1) **Iterate through the temperature array:**

    - For each day (i.e., index `i`), we check if the current temperature is **greater than** the temperature on top of the stack (which holds the indices of previous temperatures).

2) **Monotonic Decreasing Stack:**

    - The stack is used to store indices of the temperatures. It is called **monotonic decreasing** because the temperatures corresponding to the indices in the stack are in non-increasing order (from top to bottom).
    - As long as the current temperature is `higher` than the temperature at the index stored on top of the stack, we have found a **warmer day** for the day represented by the index on top of the stack. At this point:
        - We pop the index from the stack.
        - We calculate the number of days between the current day and the day represented by the popped index (`i - index`).
        - We store this result in the `result` array.

3) **Continue the Process:**

    - Push the current index `i` onto the stack.
    - Repeat the process for all days in the input array.

4) **Remaining Days:**

    - After the loop ends, any indices left in the stack correspond to days for which there is no warmer temperature in the future. These will already have `0` in the result array (since we initialized the result array with zeros).

**Algorithm in Action:**

Let's consider an example with temperatures `[73, 74, 75, 71, 69, 72, 76, 73]`:

- Initialize the stack as empty and the `result` array as` [0, 0, 0, 0, 0, 0, 0, 0]`.

- Start iterating over the array:
    1) **Day 0**: Temperature = 73. Push index 0 to the stack.
        - Stack: `[0]`

    2) **Day 1**: Temperature = 74. 74 > 73, so pop 0 from the stack. `result[0] = 1 - 0 = 1`.
        - Stack: `[]`
        - Push index 1 to the stack.
        - Stack: `[1]`
        - `result`: `[1, 0, 0, 0, 0, 0, 0, 0]`

    3) **Day 2**: Temperature = 75. 75 > 74, so pop 1 from the stack. `result[1] = 2 - 1 = 1`.
        - Stack: `[]`
        - Push index 2 to the stack.
        - Stack: `[2]`
        - `result`: `[1, 1, 0, 0, 0, 0, 0, 0]`

    4) **Day 3**: Temperature = 71. Push index 3 to the stack.
        - Stack: `[2, 3]`

    5) **Day 4**: Temperature = 69. Push index 4 to the stack.
        - Stack: `[2, 3, 4]`

    6) **Day 5**: Temperature = 72. 72 > 69, so pop 4 from the stack. `result[4] = 5 - 4 = 1`.
        - 72 > 71, so pop 3 from the stack. `result[3] = 5 - 3 = 2`.
        - Stack: `[2]`
        - Push index 5 to the stack.
        - Stack: `[2, 5]`
        - `result`: `[1, 1, 0, 2, 1, 0, 0, 0]`

    7) **Day 6**: Temperature = 76. 76 > 72, so pop 5 from the stack. `result[5] = 6 - 5 = 1`.
        - 76 > 75, so pop 2 from the stack. `result[2] = 6 - 2 = 4`.
        - Stack: `[]`
        - Push index 6 to the stack.
        - Stack: `[6]`
        - `result`: `[1, 1, 4, 2, 1, 1, 0, 0]`

    8) **Day 7**: Temperature = 73. Push index 7 to the stack.
        - Stack: `[6, 7]`

At the end of the loop, the remaining indices in the stack (`6` and `7`) represent days that have no warmer day in the future, so their `result` values remain `0`.

**Final result: `[1, 1, 4, 2, 1, 1, 0, 0]`**

### **Code**
```cpp
#include<iostream>
#include<vector>
#include<stack>


/*
- Time Complexity: O(n2)
- Space Complexity: O(n)

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        // assume the first value in the vector is zero
        std::vector<int> result(temperatures.size(), 0);

        for (size_t i = 0; i < (temperatures.size() - 1); i++)
        {
            for (size_t j = i + 1; j < (temperatures.size()); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    // when reaching the warmer day
                    // get the difference between the indecies that indicates the difference in the days
                    result[i] = j - i;
                    break; // no need for further calculations
                }
            }
        }

        return result;
    }
};
*/


/*
- Time Complexity: O(n)
- Space Complexity: O(n)
*/
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);

        std::stack<int> s; // Monotonic decreasing stack to store indices of temperatures

        for (int i = 0; i < temperatures.size(); i++) {
            // Check if the current temperature is higher than the temperature at the index stored in the stack
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int index = s.top();
                s.pop();
                result[index] = i - index; // Calculate the number of days until a warmer temperature
            }
            s.push(i); // Push the current index onto the stack
        }

        return result;
    }
};


int main()
{
    Solution s;
    std::vector<int> temperatures({73,74,75,71,69,72,76,73});

    for (int vv : s.dailyTemperatures(temperatures))
    {
        std::cout << vv << "  ";
    }
    std::cout << std::endl;


    return 0;
}
```