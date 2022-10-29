char * interpret(char * command)
{
    char* result = ( char* )malloc(sizeof( char ) * strlen( command ) + 1 );
    int iterator = 0;
    
    for ( int i = 0 ; i < strlen(command) ; i++ )
    {
        if ( command[i] == '(' && command[i + 1] == 'a' )
        {
            result[iterator++] = 'a';
            result[iterator] = 'l';
            i += 3;
        }
        else if ( command[i] == '(' && command[i + 1] == ')' )
        {
            result[iterator] = 'o';
            i++;
        }
        else if ( command[i] == 'G' )
        {
            result[iterator] = 'G';
        }
        
        iterator++;
    }
    
    result[iterator] = '\0';
    
    return result;
}

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Goal Parser Interpretation.
Memory Usage: 5.5 MB, less than 89.62% of C online submissions for Goal Parser Interpretation.
*/