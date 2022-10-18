#include <stdio.h>
#include <stdlib.h>
#include "../../Sorting-Algorithms/Bubble_Sort/Bubble_Sort.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for(int i = 0; i < n ; i++)
    {
        nums1[i + m] = nums2[i];
    }

    BubbleSort(nums1, nums1Size, NormalCompare, Ascending_Order);

    for(int j = 0; j < nums1Size; j++)
    {
        printf("%d  ", nums1[j]);
    }
}

int main()
{
    int nums1[6] = {1,2,3,0,0,0}, m = 3, nums2[3] = {2,5,6}, n = 3;

    merge(&nums1, m + n, m, &nums2, n, n);

    return 0;
}
