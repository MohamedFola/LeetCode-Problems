bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
    /* you can achieve a straight line using any two lines */
    if ( coordinatesSize == 2 ) return true;
    
    float slope;
    
    /* check for x axis */
    if ( coordinates[0][0] == coordinates[1][0] ) 
    {
        for ( int i = 2 ; i < coordinatesSize ; i++ )
        {
            if ( coordinates[i][0] != coordinates[0][0] ) return false;
        }
        
        return true;
    }
    /* check for y axis */
    else if ( coordinates[0][1] == coordinates[1][1] )
    {
        for ( int i = 2 ; i < coordinatesSize ; i++ )
        {
            if ( coordinates[i][1] != coordinates[0][1] ) return false;
        }
        
        return true;
    }
    
    /* cross product rule */
    for ( int i = 0 ; i < coordinatesSize - 2 ; i++)
    {
        if ( ( ( coordinates[i][1] - coordinates[i + 1][1] ) * ( coordinates[i][0] - coordinates[i + 2][0] ) ) != ( ( coordinates[i][1] - coordinates[i + 2][1] ) * ( coordinates[i][0] - coordinates[i + 1][0] ) ) ) return false;
    }
    
    return true;
}