

bool isPalindrome(int x)
{
    bool Local_boolStatus = false;
    
    int Local_intReversed = 0;
    
    /* Check for numbers form 0 to 9 which always Palindrome */
    if(x == 0 && x < 10)
    {
        Local_boolStatus = true;
        return Local_boolStatus;
    }
    
    
    /* Check for Negative Numbers and Numbers end with 0 but not 0 itself */
    if((x < 0) || ((x != 0) && (x % 10 == 0)))
    {
        Local_boolStatus = false;
        return Local_boolStatus;
    }

    while(Local_intReversed < x)
    {
        Local_intReversed = (Local_intReversed * 10) + (x % 10);
        x /= 10;
    }
    
    
    /*
        Local_intReversed == x         --> is for even numbers
        (Local_intReversed / 10) == x  --> is for odd numbers
    */
    if((Local_intReversed == x) || ((Local_intReversed / 10) == x))
    {
        Local_boolStatus = true;
    }
    
    return Local_boolStatus;
}