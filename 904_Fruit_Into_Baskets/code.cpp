#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

class Solution {  
public:
    int totalFruit(std::vector<int>& fruits) {
        int max_number_of_fruits = INT_MIN, left_pointer = 0;
        std::unordered_map<int, int> fruit_count;

        for(int right_pointer = 0; right_pointer < fruits.size(); right_pointer++)
        {
            fruit_count[fruits[right_pointer]]++;

            while(fruit_count.size() > 2)
            {
                fruit_count[fruits[left_pointer]]--;

                if(fruit_count[fruits[left_pointer]] == 0)
                    fruit_count.erase(fruits[left_pointer]);

                left_pointer++;
            }

            max_number_of_fruits = std::max(max_number_of_fruits, right_pointer - left_pointer + 1);
        }

        return max_number_of_fruits;
    }
};

int main()
{
    Solution s;

    std::vector<int> v;

    v = {1,2,1};
    std::cout << s.totalFruit(v) << std::endl << std::endl;
    v = {0,1,2,2};
    std::cout << s.totalFruit(v) << std::endl << std::endl;
    v = {1,2,3,2,2};
    std::cout << s.totalFruit(v) << std::endl << std::endl;
    v = {3,3,3,1,2,1,1,2,3,3,4};
    std::cout << s.totalFruit(v) << std::endl << std::endl;

    return 0;
}