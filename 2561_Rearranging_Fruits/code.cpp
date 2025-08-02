#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::map<int, int> fruit_freq;
        int fruits = basket1.size();
        int min_val = INT_MAX;

        // creating the frequency array and keep tracking the minimum value in both baskets
        for(int fruit = 0; fruit < fruits; fruit++)
        {
            fruit_freq[basket1[fruit]]++;
            fruit_freq[basket2[fruit]]--;
            min_val = std::min({min_val, basket1[fruit], basket2[fruit]});
        }

        std::vector<int> transfers;

        // calculate the transfers needed to get the equal baskets
        // if the frequency of a fruit is odd, then we can't balance the baskets
        for(auto const& fruit:fruit_freq)
        {    
            if(abs(fruit.second) % 2 != 0) return -1;
            for(int i = 0; i < (abs(fruit.second) / 2); i++)
                transfers.push_back(fruit.first);
        }

        // calculate the minimum cost by adding the first half of the transfer array
        // making one move using an unbalanced element should be < two moves using minimum value of the fruits
        // for example: b1 = {1,2,3,7,7} and b2 = {1,2,3,8,8} 
        // we only need to swap 7 and 8, and if we swapped them using min(7, 8) the cost will be 7
        // but if we done two swaps using minimum value which is 1 the cost will be 1 + 1
        // first swap will be swapping 1 with 7 -> b1 = {1,2,3,1,7} and b2 = {7,2,3,8,8} and cost = 1
        // second swap will be swapping 1 again but with 8 -> b1 = {1,2,3,8,7} and b2 = {7,2,3,1,8} and cost = 1 + 1 = 2
        // so using minimum value 2 times is efficient here
        // so for generalizing the rule we check for the min between transfer[i] and 2*min_val
        long long min_cost = 0;
        for(int fruit = 0; fruit < transfers.size() / 2; fruit++)
            min_cost += std::min(transfers[fruit], 2*min_val);
        
        return min_cost;
    }
};

int main()
{
    Solution s;

    std::vector<int> b1, b2;

    b1 = {5,5,8,8,8,8,9,9,6};
    b2 = {7,7,7,6,7,7,7,10,10};
    std::cout << s.minCost(b1, b2) << std::endl;

    return 0;
}