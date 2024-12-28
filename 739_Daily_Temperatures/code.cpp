#include<iostream>
#include<vector>
#include<stack>


/*
- This solution takes very long time with the large array
- This solution is not accepted on leet code

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
This solution is the accepted one when using stack as it saves a lot of time and works with very large arrays
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