#include<iostream>
#include<vector>



class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> asteroids_after_explosion;

        // loop for each asteroid and check if it will be explode
        for (int& asteroid : asteroids)
        {
            bool is_exploded = false;
            // check if there is an asteroid in the vector or not
            // also check if the asteroid is going in the negative direction to collapse with the asteroid going in the right direction
            // NOTE: it asteroid is going right and asteroids_after_explosion.back() is going left no explosion will happen
            while (!(asteroids_after_explosion.empty()) && asteroid < 0 && asteroids_after_explosion.back() > 0)
            {
                // if the asteroid is large in size so we need to destory the asteroids_after_explosion.back() by poping it
                // and then check again if the asteroid will collapse or not
                if (-(asteroid) > (asteroids_after_explosion.back()))
                {
                    asteroids_after_explosion.pop_back();
                    continue;
                }
                // if the asteroid is in the same size of the asteroids_after_explosion.back() then destory both and go to check the next asteroid
                else if (-(asteroid) == (asteroids_after_explosion.back()))
                {
                    asteroids_after_explosion.pop_back();
                }
                
                is_exploded = true;
                break;
            }

            if (!is_exploded)
                asteroids_after_explosion.push_back(asteroid);
        }
        

        return asteroids_after_explosion;
    }
};

int main()
{
    Solution s;
    std::vector<int> v {-2, -1, 1, 2};

    for (auto vv:s.asteroidCollision(v))
    {
        std::cout << vv << "  ";
    }
    std::cout << std::endl;

    return 0;
}