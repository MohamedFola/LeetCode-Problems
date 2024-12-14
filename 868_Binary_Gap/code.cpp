#include<iostream>

class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int sol = 0;
        for (int i = 0; i < 32; i++)
        {
            if( n & (1 << i))
            {
                if (last == -1) last = i;
                else
                {
                    sol = std::max(sol, i - last);
                    last = i;
                }
            }
        }
        
        return sol;
    }
};

int main()
{
    Solution s;
    int n;

    std::cout << "Please enter the number: "; std::cin >> n;
    while(n > 0)
    {
        std::cout << s.binaryGap(n) << "\n";
        std::cout << "Please enter the number: "; std::cin >> n;
    }


    return 0;
}