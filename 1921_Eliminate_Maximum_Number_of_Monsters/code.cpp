#include<iostream>
#include<algorithm> // for using sort function
#include<vector>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) 
    {
        int size = dist.size();

        // we will always be able to have our first kill
        int killed_monsters = 1;

        // data set to store time taken be each monster to reach the town
        std::vector<double> minutes(size, 0);

        // calculate the time taken each monster to reach the town
        // then sort it to get the nearest monster to the town
        for(int i = 0; i < size; i++)
            minutes[i] = ((double)dist[i] / speed[i]);
        std::sort(minutes.begin(), minutes.end()); // O(nLog(n))

        // we get the first kill in all cases
        // we will start calculating the number of monsters starting from the second one
        // for each monster time we will subtract the reloading time(which is represented by the loop index)
        // we lost if the reloading time is greater than the time taken be the monster to reach the town
        for(int reload_number = 1; (reload_number < size) && (reload_number < minutes[reload_number]); reload_number++) // O(n)
            killed_monsters++; // if condition is false we will kill the monster so we will incremenet the killed monster
        
        // return the number of the killed monsters
        return killed_monsters;
    }
};

int main()
{
    Solution s;

    std::vector<int> dist = {3, 2, 4};
    std::vector<int> speed = {5, 3, 2};
    std::cout << s.eliminateMaximum(dist, speed) << "\n";
    
    dist = {1, 3, 4};
    speed = {1, 1, 1};
    std::cout << s.eliminateMaximum(dist, speed) << "\n";
    
    dist = {1, 1, 2, 3};
    speed = {1, 1, 1, 1};
    std::cout << s.eliminateMaximum(dist, speed) << "\n";
    
    dist = {4, 2, 3};
    speed = {2, 1, 1};
    std::cout << s.eliminateMaximum(dist, speed) << "\n";

    return 0;
}