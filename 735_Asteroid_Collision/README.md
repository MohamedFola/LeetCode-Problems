# 735. Asteroid Collision
## 📚 Table of Contents
- [Requirements of the Problem](#requirements)
- [Examples](#example)
- [Solution Illustration](#solution)
- [Code](#code)

### **Requirements of the Problem**
We are given an array `asteroids` of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
### **Examples**
**Example 1:**

    Input: asteroids = [5,10,-5]
    Output: [5,10]
    Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
**Example 2:**

    Input: asteroids = [8,-8]
    Output: []
    Explanation: The 8 and -8 collide exploding each other.
**Example 3:**

    Input: asteroids = [10,2,-5]
    Output: [10]
    Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

### **Solution Illustration**
**Code Walkthrough:**
```cpp
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> asteroids_after_explosion;
```
- `asteroids_after_explosion`: This vector will hold the remaining asteroids after all the collisions have been processed.
- `Input`: asteroids is a vector of integers, representing the asteroids.
```cpp
// loop for each asteroid and check if it will be explode
for (int& asteroid : asteroids)
{
    bool is_exploded = false;
```
- We iterate through each asteroid in the `asteroids` vector.
- `is_exploded`: This flag will help determine if the current asteroid gets destroyed (collides) during the process.
```cpp
// check if there is an asteroid in the vector or not
// also check if the asteroid is going in the negatidirection to collapse with the asteroid going in the rigdirection
// NOTE: if asteroid is going right aasteroids_after_explosion.back() is going left, no explosiwill happen
while (!(asteroids_after_explosion.empty()) && asteroid < 0 asteroids_after_explosion.back() > 0)
{
```
- We enter a `while` loop to check if the current asteroid will collide with an asteroid in `asteroids_after_explosion`:
    - The conditions to enter this loop are:
        1. `!asteroids_after_explosion.empty()`: There must be at least one asteroid already in asteroids_after_explosion to potentially collide with the current asteroid.
        2. `asteroid < 0`: The current asteroid must be moving to the left (negative direction).
        3. `asteroids_after_explosion.back() > 0`: The asteroid at the back of `asteroids_after_explosion` must be moving to the right (positive direction).
- If these conditions are true, a collision is possible, and we need to check which asteroid survives.
```cpp
// if the asteroid is larger in size, we need to destthe asteroids_after_explosion.back() by popping it
// and then check again if the asteroid will collapse or not
if (-(asteroid) > (asteroids_after_explosion.back()))
{
    asteroids_after_explosion.pop_back();
    continue;
}
```
- If the absolute value of the current asteroid (moving left) is greater than the asteroid at the back of the `asteroids_after_explosion` vector (moving right), the left-moving asteroid destroys the right-moving one.
- We pop the back of `asteroids_after_explosion` and continue checking if the current asteroid will collide with another asteroid in `asteroids_after_explosion`.
```cpp
    // if the asteroid is the same size as tasteroids_after_explosion.back(), destroy both and break
    else if (-(asteroid) == (asteroids_after_explosion.back()))
    {
        asteroids_after_explosion.pop_back();
    }
    
    is_exploded = true;
    break;
}
```
- If the current asteroid has the same size as the asteroid in `asteroids_after_explosion` (moving right), both asteroids destroy each other.
- We pop the back of `asteroids_after_explosion` and set `is_exploded = true` to mark that the asteroid was destroyed, and we break out of the `while` loop because no further collisions are possible with the current asteroid.
```cpp
    if (!is_exploded)
        asteroids_after_explosion.push_back(asteroid);
}
```
- If the current asteroid has not exploded (it did not collide with any asteroid in `asteroids_after_explosion`), we push it to `asteroids_after_explosion`.
- This ensures that all surviving asteroids are accumulated in `asteroids_after_explosion`.
```cpp
        return asteroids_after_explosion;
    }
};
```
- After processing all asteroids, the function returns the `asteroids_after_explosion` vector, which contains the remaining asteroids after all collisions.

**Example Walkthrough:**

***Input***: `asteroids = {5, 10, -5}`
1) **Initial State:**

    - `asteroids = {5, 10, -5}`
    - `asteroids_after_explosion = []`

2) **First Iteration (asteroid = 5):**

    - `5` is moving right, so it is simply added to `asteroids_after_explosion`.
    - `asteroids_after_explosion = {5}.`

3) **Second Iteration (asteroid = 10):**

    - `10` is moving right, so it is added to `asteroids_after_explosion`.
    - `asteroids_after_explosion = {5, 10}.`

4) **Third Iteration (asteroid = -5):**

    - `-5` is moving left, so we check if it will collide with the last asteroid in `asteroids_after_explosion`, which is `10` (moving right).
    - Since `-5` is smaller than `10`, it is destroyed, and `10` survives. So, `10` is removed from `asteroids_after_explosion`.
    - Now, `asteroids_after_explosion = {5}`.
    - Next, we check if `-5` will collide with `5`. Since `-5` is moving left and `5` is moving right, no collision happens, and `-5` is added to `asteroids_after_explosion`.
    - `asteroids_after_explosion = {5, -5}`.
    
**Output: `{5, -5}`**
### **Code**
```cpp
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
```