/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize)
{
    *returnSize = n;
    
    // pointer to array of array of char
    char** Temp = (char**)malloc(sizeof(char*) * n);
    
    for(int i = 0 ; i < n ; i++)
    {
        Temp[i] = (char*)malloc(sizeof(char) * 9);
           
        if(((i + 1) % 3) == 0 && ((i + 1) % 5) == 0)
        {
            Temp[i] = "FizzBuzz";
        }
        else if(((i + 1) % 3) == 0)
        {
            Temp[i] = "Fizz";
        }
        else if(((i + 1) % 5) == 0)
        {
            Temp[i] = "Buzz";
        }
        else
        {
            // Converting int to char
            sprintf(Temp[i], "%d", i + 1);
        }
    }
    
    return Temp;
}