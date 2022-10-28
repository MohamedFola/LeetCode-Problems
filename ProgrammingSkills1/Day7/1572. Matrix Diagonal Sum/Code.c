int diagonalSum(int** mat, int matSize, int* matColSize)
{
    int sum = 0;
    
    for ( int i = 0 ; i < matSize ; i++ )
    {
        if ( ( matSize - 1 ) - i != i )
        {
            sum += mat[i][i] + mat[ ( matSize - 1 ) - i ][i];
        }
        else
        {
            sum += mat[i][i];
        }
    }
    
    return sum;
}