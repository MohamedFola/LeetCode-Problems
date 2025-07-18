#include<iostream>
#include<algorithm>
#include<vector>

class Solution
{
public:
    void wiggleSort_O_nlogn_v1(std::vector<int> &nums)
    {
        // sort the array
        std::sort(nums.begin(), nums.end()); // O(nLog(n))

        // swap num[i] and num[i+1] starting from i = 1
        for(int i = 1; i < (nums.size() - 1); i+=2) // O(n)
        {
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
        }

        // for example: vector = {3, 5, 2, 1, 6, 4}
        // after sorting the array we get this -> {1, 2, 3, 4, 5, 6}
        // after swapping num[i] with num[i + 1] -> {1 , 3, 2, 5, 4, 6}
        // this solution gives us the required formula -> num[0] <= num[1] >= num[2] <= num[3]...
    }

    void wiggleSort_O_nlogn_v2(std::vector<int> &nums)
    {
        // sort the array
        std::sort(nums.begin(), nums.end()); // O(nLog(n))

        std::vector<int> result;

        // loop from the start of the data set to the n/2 and from n to n/2 where n is the size of the data set
        // take element from left and add it the the final array and take one element from rigth and add it to the final array
        // and increment left and decremenet right and so on
        int left = 0, right = nums.size() - 1;
        while (left <= right) // O(n/2)
        {
            result.push_back(nums[left++]);
            result.push_back(nums[right--]);
        }
        
        // assign the new sorted array to the passed data set
        nums = result;

        // for example: vector = {3, 5, 2, 1, 6, 4}
        // after sorting the array we get this -> {1, 2, 3, 4, 5, 6}
        // we divide the array into two arrays -> 1 2 3 and 6 5 4
        // we take one element from each sub-array and assign it to the result vector
        // so when left = 0 and right = 5 -> result = {1 , 6}
        // when left = 1 and right = 4 -> result = {1 , 6, 2, 5}
        // when left = 2 and right = 3 -> result = {1 , 6, 2, 5, 3, 4}
        // when left = 3 and right = 2 -> loop is broken as the condition is not valid anymore
        // so the final array ensures the required formula
    }

    void wiggleSort_O_n(std::vector<int> &nums)
    {
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if((i % 2 == 0) && (nums[i] > nums[i + 1])) // for even -> 0 2 4 ... condition is nums[i] <= nums[i + 1]
                std::swap(nums[i], nums[i + 1]);
                
            else if((i % 2 != 0) && (nums[i] < nums[i + 1])) // for odd i -> 1 3 5 ... condition is nums[i] >= nums[i + 1]
                std::swap(nums[i], nums[i + 1]);
        }
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {3,5,2,1,6,4};
    s.wiggleSort_O_nlogn_v1(v);
    for(auto const& ele:v)
        std::cout << ele << "  ";
    std::cout << std::endl;

    v = {3,5,2,1,6,4};
    s.wiggleSort_O_nlogn_v2(v);
    for(auto const& ele:v)
        std::cout << ele << "  ";
    std::cout << std::endl;

    v = {3,5,2,1,6,4};
    s.wiggleSort_O_n(v);
    for(auto const& ele:v)
        std::cout << ele << "  ";
    std::cout << std::endl;
    
    return 0;
}