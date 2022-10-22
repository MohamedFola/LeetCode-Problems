bool canConstruct(char * ransomNote, char * magazine)
{
    int Letters[26] = {0};
    
    for(int i = 0 ; magazine[i] != '\0' ; i++)
    {
        Letters[magazine[i] - 'a']++; 
    }
    
    for(int i = 0 ; ransomNote[i] != '\0' ; i++)
    {
        if(Letters[ransomNote[i] - 'a'] == 0)
        {
            return false;
        }
        
        Letters[ransomNote[i] - 'a']--;
    }
    
    return true;
}

/*
Runtime: 7 ms, faster than 71.16% of C online submissions for Ransom Note.
Memory Usage: 6.5 MB, less than 59.29% of C online submissions for Ransom Note.
*/