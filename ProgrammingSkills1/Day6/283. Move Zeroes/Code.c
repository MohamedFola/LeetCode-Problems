void moveZeroes(int* nums, int numsSize)
{
    if ( numsSize == 1 ) return;
    
    int zeroIndex = -1;
    
    for ( int i = 0 ; i < numsSize ; i++)
    {
        if ( nums[i] == 0 && zeroIndex < 0)
        {
            zeroIndex = i;
        }
        else if ( nums[i] != 0 && zeroIndex >= 0 )
        {
            /* swap */
            nums[zeroIndex] = nums[i];
            nums[i] = 0;
            zeroIndex++;
        }
    }
}