#include<iostream>
#include<algorithm> // for using sort function
#include<vector>

class Solution {
public:
    int findUnsortedSubarray_with_sort(std::vector<int>& nums) {
        int vector_size = nums.size();
        std::vector<int> sorted_vector = nums;

        // sort the new array
        std::sort(sorted_vector.begin(), sorted_vector.end());

        int sub_vector_start = -1, sub_vector_end = -1;
        // loop through the array
        // the first unmatched elements will be the start of the unsorted sub-array
        // loop through the rest of the array to find the last unmatched elements, then this will be the end of the unsorted sub-array
        for(int i = 0; i < vector_size; i++)
        {
            if ((sorted_vector[i] != nums[i]))
            {
                // check if we got the start of the unsorted sub-array
                if(sub_vector_start == -1) 
                    sub_vector_start = i;
                // if we got the start of the unsorted sub-array, then the unmatched elements will be the last of the unsorted sub-array
                else
                    sub_vector_end = i;
            }
        }

        // if the index is not updated then the array is sorted or only contains 1 element
        if(sub_vector_start == -1) return 0;

        return (sub_vector_end - sub_vector_start + 1);
    }

    int findUnsortedSubarray_without_sort(std::vector<int>& nums) {
        int vector_size = nums.size();

        int sub_vector_end = -1;
        int max = INT_MIN;
        // by going from right to left -> nums[i] < nums[i + 1]
        // find the last index of the unsorted sub-array by keeping the max element
        // if the max element is > nums[i] this means that a previous element is not in its right place
        // loop through all the array to find the last element that is not in its right place, this will be the end of the unsorted sub-array
        for(int i = 0; i < vector_size; i++)
        {
            max = std::max(max, nums[i]);
            if(max > nums[i])
                sub_vector_end = i;
        }

        int sub_vector_start = -1;
        int min = INT_MAX;
        // by going from left to right -> nums[i] > nums[i - 1]
        // find the first index of the unsorted sub-array by keeping the min element
        // if the min element is < nums[i] this means that a previous element is not in its right place
        // loop through all the array to find the first element that is not in its right place, this will be the start of the unsorted sub-array
        for(int i = (vector_size - 1); i >= 0; i--)
        {
            min = std::min(min, nums[i]);
            if(min < nums[i])
                sub_vector_start = i;
        }

        // if the index is not updated then the array is sorted or only contains 1 element 
        if(sub_vector_start == -1) return 0;
        
        return (sub_vector_end - sub_vector_start) + 1;
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {2, 6, 4, 8, 10, 9, 15};
    std::cout << s.findUnsortedSubarray_with_sort(v) << "\n";
    v = {2, 6, 4, 8, 10, 9, 15};
    std::cout << s.findUnsortedSubarray_without_sort(v) << "\n";

    v = {1, 2, 3, 4};
    std::cout << s.findUnsortedSubarray_with_sort(v) << "\n";
    v = {1, 2, 3, 4};
    std::cout << s.findUnsortedSubarray_without_sort(v) << "\n";

    v = {1};
    std::cout << s.findUnsortedSubarray_with_sort(v) << "\n";
    v = {1};
    std::cout << s.findUnsortedSubarray_without_sort(v) << "\n";

    v = {2, 6, 4, 8, 10, 9, 6};
    std::cout << s.findUnsortedSubarray_with_sort(v) << "\n";
    v = {2, 6, 4, 8, 10, 9, 6};
    std::cout << s.findUnsortedSubarray_without_sort(v) << "\n";

    return 0;
}