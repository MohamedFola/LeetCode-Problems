/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int* resultArray = ( int* )malloc( sizeof(int) * nums1Size );
    ( *returnSize ) = nums1Size;
    
    int flag;
    
    for( int i = 0 ; i < nums1Size ; i++ )
    {
        resultArray[i] = -1;
        flag = 0;
        
        for ( int j = 0 ; j < nums2Size ; j++ )
        {
            if ( nums1[i] == nums2[j] ) flag = 1;   
            if ( flag && nums2[j] > nums1[i] ) { resultArray[i] = nums2[j]; break; }
        }
    }
    
    return resultArray;
}