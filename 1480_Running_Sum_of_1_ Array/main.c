#include <stdio.h>
#include <stdlib.h>

/* Difficulty --> Easy */

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    for(int i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i - 1];
    }

    return nums;
}

int main()
{
    int Array[4] = {1, 2, 3, 4};
    int* x = NULL;
    int r = NULL;

    x = runningSum(Array, 4, &r);

    for(int i = 0; i < 4; i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}
