#include<iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;

        int prev = 0, result = 1;
        for (size_t i = 1; i < n; i++)
        {
            int temp = result;
            result = result + prev;
            prev = temp;
        }
        
        return result;
    }
};

int main()
{

    Solution s;

    cout << s.fib(6) << endl;

    return 0;
}