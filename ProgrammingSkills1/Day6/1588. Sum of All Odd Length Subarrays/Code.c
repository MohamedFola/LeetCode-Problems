int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int totalSum = 0;

    /* sum of all array elements for length of 1 for sub-arrays */
    for ( int i = 0 ; i < arrSize ; i++ )
    {
        totalSum += arr[i];
    }

    for ( int k = 3; k <= arrSize ; k += 2)
    {
        int sum = 0;
        int i;

        /* calculate the initial sum */
        for ( i = 0 ; i < k ; i++)
        {
            sum += arr[i];
        }

        totalSum += sum;

        i = 1;

        while ( ( i + k ) <= arrSize)
        {
            sum = sum - arr[i - 1] + arr[i + k - 1];
            totalSum += sum;
            i++;
        }
    }

    return totalSum;
}