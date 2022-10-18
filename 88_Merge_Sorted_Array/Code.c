#define Ascending_Order    1


void BubbleSort(int* Copy_pintArray, int Copy_intArraySize, int (*Copy_pintPtrFunction)(int, int , int), int Copy_intOrder)
{
	if(Copy_pintArray != NULL && Copy_pintPtrFunction != NULL)
	{
		int Local_intCounter1, Local_intCounter2, Local_intIndex, Local_intTempVar, Local_intFlag;
	
		for(Local_intCounter1 = 1; Local_intCounter1 < Copy_intArraySize; Local_intCounter1++)
		{
			Local_intFlag = 0;
			for(Local_intCounter2 = 0; Local_intCounter2 < Copy_intArraySize - Local_intCounter1; Local_intCounter2++)
			{
				if(Copy_pintPtrFunction(Copy_pintArray[Local_intCounter2], Copy_pintArray[Local_intCounter2 + 1], Copy_intOrder) > 0)
				{
					/* Swapping Operation */
					Local_intTempVar = Copy_pintArray[Local_intCounter2];
					Copy_pintArray[Local_intCounter2] = Copy_pintArray[Local_intCounter2 + 1];
					Copy_pintArray[Local_intCounter2 + 1] = Local_intTempVar;
					
					/* Indication for swapping process */
					Local_intFlag = 1;
				}
			}
			
			/* If there is no swapping, it means that the array is sorted and no need for additional looping */
			if(Local_intFlag == 0) break; 
		}
	}
	else
	{
		/* DO NOTHING */
	}
	
}

int NormalCompare(int Copy_intFirstElement, int Copy_intSecondElement, int Copy_intOrder)
{
    if(Copy_intOrder == Ascending_Order)
        return (Copy_intFirstElement) - (Copy_intSecondElement);  /* returnnig the minus to know the sign of the operation */
    return (Copy_intSecondElement) - (Copy_intFirstElement);
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for(int i = 0; i < n ; i++)
    {
        nums1[i + m] = nums2[i];
    }

    BubbleSort(nums1, nums1Size, NormalCompare, Ascending_Order);
}