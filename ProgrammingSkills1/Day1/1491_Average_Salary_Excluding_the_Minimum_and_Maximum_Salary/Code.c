double average(int* salary, int salarySize)
{
    int max, min, sum;
    max = min = sum = salary[0];
    
    for(int i = 1 ; i <  salarySize ; i++)
    {
        sum += salary[i];
        
        if(salary[i] > max) max = salary[i];
        if(salary[i] < min) min = salary[i];
    }
    
    return (sum - max - min) / (salarySize - 2.0);
}

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Average Salary Excluding the Minimum and Maximum Salary.
Memory Usage: 5.6 MB, less than 98.09% of C online submissions for Average Salary Excluding the Minimum and Maximum Salary.
*/