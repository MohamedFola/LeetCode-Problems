#include<iostream>
#include<algorithm> // for using sort function
#include<vector>

class Solution {
public:
    int maxProfitAssignment_v1(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker)
    {
        int worker_number = worker.size();
        int difficulty_number = difficulty.size();
        int total_profit = 0;

        for(int i = 0; i < worker_number; i++) // O(m * n)
        {
            int max_profit = 0;
            for(int j = 0; j < difficulty_number; j++)
            {
                // if the ability of the worker > difficulity of the job
                // then get the job(that the worker can do) with the max profit and assign it to the worker
                if(worker[i] >= difficulty[j])
                    max_profit = std::max(max_profit, profit[j]);
            }

            // add the max profit that the worker can get to the total profit
            total_profit += max_profit;
        }

        return total_profit;
    }

    int maxProfitAssignment_v2(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker)
    {
        int worker_number = worker.size();
        int difficulty_number = difficulty.size();
        int total_profit = 0;

        // add the job difficulity and profit to a pair and sort them
        std::vector<std::pair<int, int>> jobs;
        for(int job = 0; job < difficulty_number; job++)
            jobs.push_back({difficulty[job], profit[job]});
        std::sort(jobs.begin(), jobs.end());

        // sort the array of workers
        std::sort(worker.begin(), worker.end());

        // loop through each worker to get the job with the max profit and also its difficulity is sutiable for the worker
        // as we sorted the array of worker and the jobs we now can cancel some duplicate searches
        // for example we have workerA and workerB with 10 and 15 abilites, and the jobs are {{5,7}, {10,2}, {12,6}, {15,3}, {40,17}}
        // workerA will scan 5 and 10 and will get max profit which is 7
        // workerB shouldn't scan 5 and 10 as they are already scaned by workerA, so workerB will scan 12 and 15 and get the max profit which is 7
        int job = 0, max_profit = 0;
        for(int employee = 0; employee < worker_number; employee++)
        {
            for(; (job < difficulty_number) && (worker[employee] >= jobs[job].first); job++)
                max_profit = std::max(max_profit, jobs[job].second);

            // add the max profit that the worker can get to the total profit
            total_profit += max_profit;
        }

        return total_profit;
    }
};

int main()
{
    Solution s;

    std::vector<int> d = {2,4,6,8,10};
    std::vector<int> p = {10,20,30,40,50};
    std::vector<int> w = {4,5,6,7};
    std::cout << "Max Profit: " << s.maxProfitAssignment_v1(d, p , w) << "\n"; // 100
    std::cout << "Max Profit: " << s.maxProfitAssignment_v2(d, p , w) << "\n"; // 100
    
    d = {85,47,57};
    p = {24,66,99};
    w = {40,25,25};
    std::cout << "Max Profit: " << s.maxProfitAssignment_v1(d, p , w) << "\n"; // 0
    std::cout << "Max Profit: " << s.maxProfitAssignment_v2(d, p , w) << "\n"; // 0
    
    d = {2,4,6,8,10};
    p = {50,20,30,40,10};
    w = {4,5,6,7};
    std::cout << "Max Profit: " << s.maxProfitAssignment_v1(d, p , w) << "\n"; // 200
    std::cout << "Max Profit: " << s.maxProfitAssignment_v2(d, p , w) << "\n"; // 200
    
    d = {85,47,57};
    p = {24,66,99};
    w = {90,87,100};
    std::cout << "Max Profit: " << s.maxProfitAssignment_v1(d, p , w) << "\n"; // 297
    std::cout << "Max Profit: " << s.maxProfitAssignment_v2(d, p , w) << "\n"; // 297
    
    d = {85,47,57};
    p = {24,66,99};
    w = {90,87,50};
    std::cout << "Max Profit: " << s.maxProfitAssignment_v1(d, p , w) << "\n"; // 264
    std::cout << "Max Profit: " << s.maxProfitAssignment_v2(d, p , w) << "\n"; // 264
    
    return 0;
}