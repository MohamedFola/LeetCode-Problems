int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;
    (*returnSize) = 2;

    int* arr = (int*)malloc((*returnSize) * sizeof(int));

    for(i=0; i<numsSize-1; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
            }
        }
    }

    return arr;
}