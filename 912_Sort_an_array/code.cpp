#include<iostream>
#include<vector>
#include<map>

/*
    time: 123 ms
    space: 101.5 MB
*/
class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::vector<int> result;

        std::map<int, int> frq;

        for (int i = 0; i < nums.size(); i++)
            frq[nums[i]]++;


        for(auto const element:frq)
            for (int i = 0; i < element.second; i++)
                result.push_back(element.first);
        
        
        return result;
    }
};

/*
    time: 14 ms
    space: 77.4 MB
*/
class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        const int LOWER_RANGE = 50000;
        int max = nums[0];

        // get the max number
        for(auto const& element:nums)
            if(element > max)
                max = element;

        // shift the range using lower range to start from 0
        max += LOWER_RANGE;

        // map of the frequencies
        std::vector<int> freq((max + 1));

        // calculate the frequency of each element
        for(auto const& element:nums)
            freq[(element + LOWER_RANGE)]++;

        // push each element in the data set with frequency that stored in the freq array
        int idx = 0;
        for(int i = 0; i <= max; i++)
            for(int j = 0; j < freq[i]; j++, idx++)
                nums[idx] = (i - LOWER_RANGE);

        // return the result vector
        return nums;
    }
};
