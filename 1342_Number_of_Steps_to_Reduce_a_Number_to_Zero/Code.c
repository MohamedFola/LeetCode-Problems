// Normal approach
int numberOfSteps(int num)
{
    int steps = 0;
    
    while(num > 0)
    {
        if(((num) % 2) == 0)
        {
            num /= 2;
        }
        else
        {
            num--;
        }
        
        steps++;
    }
    
    return steps;
}


// Bit manipulation approach
int numberOfSteps(int num)
{
    int steps = 0;
    
    while(num > 0)
    {
        // after mask if the result is 0 --> even
        // after mask if the result is 1 --> odd
        if(((num) & 1) == 0)
        {
            // shifting left performs a division by 2
            num >>= 1;
        }
        else
        {
            num--;
        }
        
        steps++;
    }
    
    return steps;
}