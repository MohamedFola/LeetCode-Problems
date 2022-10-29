char * mergeAlternately(char * word1, char * word2)
{
    char* result = ( char* )malloc( sizeof(char) * ( strlen( word1 ) + strlen( word2 ) + 1 ) );
    int w1 = 0, w2 = 0, i = 0;
    
    while ( word1[w1] != '\0' || word2[w2] != '\0' )
    {
        if ( w1 < strlen( word1 ) ) result[i++] = word1[w1++];
        if ( w2 < strlen( word2 ) ) result[i++] = word2[w2++];
    }
    
    result[i] = '\0';
    
    return result;
}

/* 
Runtime: 0 ms, faster than 100.00% of C online submissions for Merge Strings Alternately.
Memory Usage: 5.9 MB, less than 48.44% of C online submissions for Merge Strings Alternately.
*/