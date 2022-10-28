/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    int m = matSize;
    int n = ( *matColSize );
    
    if ( ( m * n ) != ( r * c ) ) 
    {
        ( *returnSize ) = matSize;
        ( *returnColumnSizes ) = matColSize;
        return mat;
    }
    
    ( *returnSize ) = r;
    ( *returnColumnSizes) = malloc( sizeof( int ) * r );
    
    int** resultArray = malloc( sizeof( int* ) * r );
    
    for ( int i = 0 ; i < r ; i++ )
    {
        ( *returnColumnSizes )[i] = c;
        
        resultArray[i] = malloc( sizeof( int ) * c);
    }
    
    for ( int i = 0 ; i < m * n ; i++ )
    {
        resultArray[i / c][i % c] = mat[i / n][i % n];
    }
    
    return resultArray;
}