char findTheDifference(char * s, char * t)
{
    int sumT = 0;
    int sumS = 0;
    
    for ( int i = 0 ; t[i] != '\0' ; i++ )
    {
        sumT += ( int )t[i];
        
        if ( s[i] != '\0' ) sumS += ( int )s[i];
    }
    
    return (char)( sumT - sumS );
}