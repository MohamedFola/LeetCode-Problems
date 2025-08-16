#include<iostream>
#include<algorithm>

class Solution {
private:
    int count_leg(int m, int n, int value)
    {
        int count = 0;
        for(int row = 1; row <= m; row++)
            count += std::min((value/row), n);
        return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int start = 1, end = m * n, res = 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(count_leg(m, n, mid) >= k)
                end = mid - 1, res = mid;
            else
                start = mid + 1;
        }

        return res;
    }
};

int main()
{
    Solution s;
    int m, n, k;

    m = 3;
    n = 3;
    k = 5;
    std::cout << "Kth Smallest Number is " << s.findKthNumber(m,n,k) << std::endl; // 3

    m = 2;
    n = 3;
    k = 6;
    std::cout << "Kth Smallest Number is " << s.findKthNumber(m,n,k) << std::endl; // 6
    
    return 0;
}