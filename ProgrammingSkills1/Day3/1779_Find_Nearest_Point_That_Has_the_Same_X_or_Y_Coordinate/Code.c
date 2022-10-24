int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize)
{
    int min = INT_MAX;
    int index = -1;
    
    for(int i = 0 ; i < pointsSize ; i++)
    {
        if(points[i][0] == x || points[i][1] == y)  
        {
            if(abs(points[i][0] - x) + abs(points[i][1] - y) < min)
            {
                min = abs(points[i][0] - x) + abs(points[i][1] - y);   
                index = i;
            }
        }
    }
    
    return index;
}