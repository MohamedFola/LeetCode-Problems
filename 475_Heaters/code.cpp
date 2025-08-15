#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
private:
    bool possible(std::vector<int> houses, std::vector<int> heaters, int radius)
    {
        int heater_number = heaters.size(), house_number = houses.size(), houses_covered = 0;

        for(int heater = 0; heater < heater_number; heater++)
        {
            int distance_covered_left = heaters[heater] - radius, distance_covered_right = heaters[heater] + radius;

            while(houses_covered < house_number && houses[houses_covered] >= distance_covered_left && houses[houses_covered] <= distance_covered_right)
                houses_covered++;
        }

        return houses_covered == house_number;
    }
public:
    int findRadius_v1(std::vector<int>& houses, std::vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        int start = 0, end = std::max(*(houses.end() - 1), *(heaters.end() - 1)), res = 0;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(possible(houses, heaters, mid))
                res = mid, end = mid - 1;
            else
                start = mid + 1;
        }

        return res;
    }

    
    int findRadius_v2(std::vector<int>& houses, std::vector<int>& heaters) {
        std::sort(heaters.begin(), heaters.end());

        int radius = 0;
        for(int house = 0; house < houses.size(); house++)
        {
            int nearest_heater = std::lower_bound(heaters.begin(), heaters.end(), houses[house]) - heaters.begin();

            if(nearest_heater == heaters.size())
                radius = std::max(radius, abs(houses[house] - heaters[nearest_heater - 1]));
            else if(nearest_heater == 0)
                radius = std::max(radius, abs(houses[house] - heaters[nearest_heater]));
            else
            {
                int best_radius = std::min(abs(houses[house] - heaters[nearest_heater - 1]), abs(houses[house] - heaters[nearest_heater]));
                radius = std::max(radius, best_radius);
            }
        }

        return radius;
    }
};


int main()
{
    Solution s;

    std::vector<int> houses, heaters;

    houses = {1,2,3};
    heaters = {2};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 1
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;

    houses = {1,2,3,4};
    heaters = {1,4};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 1
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;

    houses = {1,5};
    heaters = {2};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 3
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;
    
    houses = {1,2,3};
    heaters = {3};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 2
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;
    
    houses = {1,2,13};
    heaters = {3};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 10
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;

    houses = {1,5};
    heaters = {10};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 9
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;

    houses = {1};
    heaters = {1,2,3,4};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 0
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl;

    houses = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    heaters = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    std::cout << "radius needed using version 1 is " << s.findRadius_v1(houses, heaters) << std::endl; // 161834419
    std::cout << "radius needed using version 2 is " << s.findRadius_v2(houses, heaters) << std::endl << std::endl; // 161834419
    
    return 0;
}