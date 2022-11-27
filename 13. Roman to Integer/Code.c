int romanToInt(char * s)
{
    int value['X' + 1] = 
    {
        ['I']  = 1,
        ['V']  = 5,
        ['X']  = 10,
        ['L']  = 50,
        ['C']  = 100,
        ['D']  = 500,
        ['M']  = 1000,
        ['\0'] = 0,
    };
    
    int sum = 0;
    
    for(int i = 0 ; s[i] != '\0' ; i++)
    {
        if(value[s[i]] < value[s[i + 1]]) sum -= value[s[i]];
        else                              sum += value[s[i]];
    }
    
    return sum;
}