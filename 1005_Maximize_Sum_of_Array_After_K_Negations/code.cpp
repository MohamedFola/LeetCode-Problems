#include<iostream>
#include<algorithm> // for using sort function
#include<vector>

class Solution {
public:
    /*
        - we have three cases in our problem that leads us to get this solution
            - case 1: all elements in the data set are +ve.
                1) sort the data set to get the smallest element that removing it from the sum will be the best.
                2) if k is even number we wont need to change the sign of any element as we will only foucs on changing the first one(which is the smallest one) but as the k is even the change will cancel each other.
                    ex: k = 2 and {4, 2, 3} after sorting {2, 3, 4} we will change 2 to -2 and k will be 1 and then change -2 to 2 and k will 0
                3) if k is odd and only change the first element in the data set(which is the smallest one) for one time.
                    ex: k = 3 and {4, 2, 3} after sorting {2, 3, 4} we will change 2 to -2 and k will be 2 and then change -2 to 2 and k will 1 and then change 2 to -2 and k will be 0
                4) so for all odd values of k, we can consider it k = 1, and for all even values of k we can consider it k = 0.

            - case 2: all elements in the data set are -ve.
                1) sort the data set, change the first k elements in the to +ve this will give us the biggest sum.

            - case 3: some elements in the data set are -ve and the others are +ve.
                1) sort the data set
                2) loop through all elements of the data set and think as we have two sub-data sets, one is -ve values and the other is +ve values

        - cons: not easy to understand.
        - pros: only take O(nLog(n)).
    */
    int largestSumAfterKNegations(std::vector<int>& nums, int k) 
    {
        int result = 0;
        int vector_size = nums.size();
        int min_value = INT_MAX;

        std::sort(nums.begin(), nums.end()); // O(nLog(n))
        
        // loop through all elements of the data set
        for(int i = 0; i < vector_size; i++)
        {
            // if k is not 0 and element is -ve then flip it.
            // if k reached 0 and elements are still -ve so don't need to do anything.
            // if k is not 0 and elements are +ve, we need to track the minimun value to see if we will subtract it from the sum or not according to k if it is even or odd.
            if((k) && (nums[i] < 0))
            {
                k--;
                nums[i] *= -1;
            }

            // add all elements of data set to the finial sum, for -ve values we will add them after flipping them.
            result += nums[i];

            // keep tracking the minimum value in the data set
            // note: this is important to get the minimum value between the last element in the -ve sub-data set and the first element in the +ve sub-data set
            min_value = std::min(min_value, nums[i]);
        }

        // if k is still not 0, this means that we entered the +ve sub-data set without reaching k = 0, so only need to check for the remaining k
        // if k is even, then no need to do anything
        // if k i odd, we only need to subtract the minimum value from the total sum
        // please note the we multiple the minimum with 2, as we already added it to the sum
        // assume the sum is 5+10+15=30, but we need it to be -5+10+15=20 so that we need to multiple the minimum value with 2
        if((k % 2))
            result -= (2 * min_value);

        return result;
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {4, 2, 3};
    int k = 1;
    std::cout << s.largestSumAfterKNegations(v, k) << "\n\n";
    
    v = {3, -1, 0, 2};
    k = 3;
    std::cout << s.largestSumAfterKNegations(v, k) << "\n\n";
    
    v = {2, -3, -1, 5, -4};
    k = 2;
    std::cout << s.largestSumAfterKNegations(v, k) << "\n\n";

    return 0;
}