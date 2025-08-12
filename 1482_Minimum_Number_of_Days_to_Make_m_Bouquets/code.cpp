#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
private:
    bool possible(std::vector<int>& bloomDay, int total_bouquets, int floors_per_bouquet, int waiting_day)
    {
        int bouquets = 0, adjacent_floors = 0;

        // loop through all floors and try to collect the bouquets we can create
        for(int day = 0; day < (int)bloomDay.size(); day++)
        {
            // if floor day is less than our waiting day
            // then we can take this floor
            if(bloomDay[day] <= waiting_day)
            {
                adjacent_floors++;

                // if we reached the number of floors per bouquet
                // then we now have another bouquet ready
                if(adjacent_floors >= floors_per_bouquet)
                    adjacent_floors = 0, bouquets++;

                // if we reached the total number of bouquets we need then this waiting day is suitable
                // then return true
                if(bouquets == total_bouquets)
                    return true;
            }
            // if not then restart the process as we only take the adjacent floors
            else
                adjacent_floors = 0;
        }

        return false;
    }
public:
    int minDays(std::vector<int>& bloomDay, int total_bouquets, int floors_per_bouquet) {
        // if we need 3 bouquets and 2 floors per bouquets then the total number of floors should be 6 or more
        // so if the total number of floors is less than the total number of floors needed to create n bouquets of k floors, then we can't solve this one
        if(total_bouquets > (bloomDay.size() / floors_per_bouquet))
            return -1;

        // here we are searching for the minimum waiting days untill we can for the bouquets
        // this is a monotonic increasing function, as for day 1 if we do m bouquets
        // then at day 2 we can do at least m bouquets
        // then our imaginary array that we will search inside it will be like this
        // [day1,  day2,  day3,  day4, day5 .....]
        // [false, false, false, true, true .....]
        // we need to search for the first day that gives true
        int start = 1, end = *std::max_element(bloomDay.begin(), bloomDay.end()), res = -1;

        while(start <= end)
        {
            // get a random day between 1 and the maximum waiting day
            int mid = start + (end - start) / 2;

            // if we can form m bouquets in this day
            // then this can be a possible answer but we will keep search in the left side of the array
            // to get the first day that gives true
            if(possible(bloomDay, total_bouquets, floors_per_bouquet, mid))
                res = mid, end = mid - 1;
            // if we can't form m bouquets in this day
            // this means that we are in the false side of the imaginary array
            // so search in the right side of the array
            else
                start = mid + 1;
        }

        return res;
    }
};

int main()
{
    Solution s;

    std::vector<int> v;
    int total_bouquets, floors_per_bouquet;

    v = {1,10,3,10,2};
    total_bouquets = 3;
    floors_per_bouquet = 1;
    std::cout << s.minDays(v, total_bouquets, floors_per_bouquet) << std::endl;

    v = {1,10,3,10,2};
    total_bouquets = 3;
    floors_per_bouquet = 2;
    std::cout << s.minDays(v, total_bouquets, floors_per_bouquet) << std::endl;

    v = {7,7,7,7,12,7,7};
    total_bouquets = 2;
    floors_per_bouquet = 3;
    std::cout << s.minDays(v, total_bouquets, floors_per_bouquet) << std::endl;
    
    return 0;
}