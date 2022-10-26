bool areAlmostEqual(char * s1, char * s2)
{
    char Character1, Character2;
    int Flag1 = 0, Flag2 = 0, Swap = 0;
    
    for( int i = 0 ; i < strlen(s1) && Swap < 2 ; i++ )
    {
        Character1 = s1[i];
        Character2 = s2[i];
        
        if      ( Character1 == Flag2 && Character2 == Flag1 ) Flag1 = Flag2 = 0;
        else if ( Character1 != Character2 )
        {
            Swap++;
            Flag1 = Character1;
            Flag2 = Character2;
        }
    }
    
    return ( Flag1 == 0 ) && ( Flag2 == 0 ) && ( Swap < 2 );
}