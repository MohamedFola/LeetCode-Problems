#include<iostream>
#include<math.h>

class Solution {
public:
    /*
        using math method.
        - we want to get k that forms this equation ``(k * (k + 1)) / 2 <= n`` where k is the number of rows
        - get the solution for this function -> k^2 + k - 2n <= 0
        - solution should be sqrt(2n + 0.25) - 0.5 
    */
    int arrangeCoins_v1(int n) {
        return (int)(sqrt((2.0 * (double)n) + 0.25) - 0.5);
    }

    
    /*
        using binary search method.
        - we want to get the last value that gets true from this equation -> n >= summation(k)
        - our imaginary array should be just like this -> [True, True, True, True, False, False, False, ...], and we want to get the last True in the array
    */
    bool possible(int n, long long row_number)
    {
        long sum = ((row_number + 1) * row_number) / 2;
        return n >= sum;
    }
    int arrangeCoins_v2(int n)
    {
        int start = 0, end = n, position = 0;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            // if n is still larger than or equal to the row summation, then this answer could be the right answer
            // keep searching for the last true
            if(possible(n, mid))
                position = mid, start = mid + 1;
            // if n is smaller than row summation, then we need to search the left as the right part will be false
            else
                end = mid - 1;
        }

        return position;
    }
};

int main()
{
    Solution s;

    std::cout << "Using Math: " << s.arrangeCoins_v1(8) << std::endl;
    std::cout << "Using Binary Search: " << s.arrangeCoins_v2(8) << std::endl;
    std::cout << std::endl;
    std::cout << "Using Math: " << s.arrangeCoins_v1(81) << std::endl;
    std::cout << "Using Binary Search: " << s.arrangeCoins_v2(81) << std::endl;
    
    return 0;
}