int CompareFunction(const void* number1, const void* number2)
{
    return (*(int*)number1) - (*(int*)number2);
}

int largestPerimeter(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), CompareFunction);
    
    int result = 0;
    
    for(int i = 2 ; i < numsSize ; i++)
    {
        if(nums[i] < (nums[i - 1] + nums[i - 2]))
        {
            result = nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    
    
    return result;
}

/*
Runtime: 80 ms, faster than 44.42% of C online submissions for Largest Perimeter Triangle.
Memory Usage: 7.6 MB, less than 53.02% of C online submissions for Largest Perimeter Triangle
*/