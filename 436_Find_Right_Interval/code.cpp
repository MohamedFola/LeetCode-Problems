#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

class Solution {
private:
    int BSFindFirst(std::vector<std::vector<int>> &startings, int target)
    {
        int start = 0, end = startings.size() - 1, position = -1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(target > startings[mid][0])
                start = mid + 1;
            // we need to find the first element that is "greater than" or "equal" to the target value
            else if(target <= startings[mid][0])
                end = mid - 1, position = mid;
        }

        return position;
    }
    
public:
    /*
        this version based on my own binary search
    */
    std::vector<int> findRightInterval_v1(std::vector<std::vector<int>>& intervals) {
        std::vector<int> res(intervals.size(), -1);

        // get all the starts of the intervals and map them to their right index
        std::vector<std::vector<int>> startings;
        for(int interval_index = 0; interval_index < intervals.size(); interval_index++)
            startings.push_back({intervals[interval_index][0], interval_index});

        // sort the starts to do binary search
        std::sort(startings.begin(), startings.end());

        // for each interval try to get the first start that is greater or equal to the end of this interval
        // this element will be the right hand interval
        for(int start = 0; start < startings.size(); start++)
        {
            // search for the first start that is greater or equal to the end of the interval
            int position = BSFindFirst(startings, intervals[start][1]);

            // if the position is valid just add the right index of this interval to the result vector
            // it not just keep the -1
            if(position != -1)
                res[start] = startings[position][1];
        }

        return res;
    }

    /*
        this version based on STL binay search 
    */
    std::vector<int> findRightInterval_v2(std::vector<std::vector<int>>& intervals) {
        std::vector<int> res(intervals.size(), -1);
        
        // get all the starts of the intervals and map them to their right index
        std::vector<std::pair<int, int>> startings;
        for(int interval_index = 0; interval_index < intervals.size(); interval_index++)
            startings.push_back({intervals[interval_index][0], interval_index});
        std::sort(startings.begin(), startings.end());

        for(int interval_index = 0; interval_index < startings.size(); interval_index++)
        {
            int target = intervals[interval_index][1];
            // lower bound returns the first >= element to the target
            auto position_iter = std::lower_bound(startings.begin(), startings.end(), std::make_pair(target, 0));

            // if the position iterator equals to the startings.end() this means that the end of the interval has no start that is greater than of equal to it
            // this means that the interval has no right hand interval
            if(position_iter != startings.end())
                res[interval_index] = position_iter->second;
        }
        
        return res;
    }

    /*
        this version based on STL map lower_bound
    */
    std::vector<int> findRightInterval_v3(std::vector<std::vector<int>>& intervals) {
        std::vector<int> res(intervals.size(), -1);
        
        // create an array with the start of each interval and map this start to its right index
        // NOTE: map will be sorted with respect to start automatically
        std::map<int, int> startings;
        for(int interval_index = 0; interval_index < intervals.size(); interval_index++)
            startings[intervals[interval_index][0]] = interval_index;

        for(int interval_index = 0; interval_index < startings.size(); interval_index++)
        {
            // try to find the first start that comes after the end of the interval
            // lower bound will return the first start that is >= the end of our interval
            std::map<int,int>::iterator position_iter = startings.lower_bound(intervals[interval_index][1]);

            // if element is found the iterator will not be equal to startings.end()
            if(position_iter != startings.end())
                res[interval_index] = position_iter->second;
        }

        return res;
    }

};

void print_vector(std::vector<int> res)
{
    for(auto const& ele:res)
        std::cout << ele << "  ";
    std::cout << std::endl;
}


int main()
{
    Solution s;

    std::vector<std::vector<int>> v = {{1,4},{2,3},{3,5}};
    std::vector<int> res = s.findRightInterval_v1(v);
    print_vector(res);
    res = s.findRightInterval_v2(v);
    print_vector(res);
    res = s.findRightInterval_v3(v);
    print_vector(res);
    std::cout << std::endl;
    
    v = {{1,2}};
    res = s.findRightInterval_v1(v);
    print_vector(res);
    res = s.findRightInterval_v2(v);
    print_vector(res);
    res = s.findRightInterval_v3(v);
    print_vector(res);
    std::cout << std::endl;
    
    v = {{3,4},{2,3},{1,2}};
    res = s.findRightInterval_v1(v);
    print_vector(res);
    res = s.findRightInterval_v2(v);
    print_vector(res);
    res = s.findRightInterval_v3(v);
    print_vector(res);
    std::cout << std::endl;
    
    v = {{1,3},{2,4}};
    res = s.findRightInterval_v1(v);
    print_vector(res);
    res = s.findRightInterval_v2(v);
    print_vector(res);
    res = s.findRightInterval_v3(v);
    print_vector(res);
    std::cout << std::endl;
    
    return 0;
}