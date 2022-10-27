

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize)
{
    int Richest = 0;
    
    for(int Customer = 0; Customer < accountsSize; Customer++)
    {
        int temp = 0;
        
        for(int Banks = 0; Banks < (*accountsColSize); Banks++)
        {
            temp += accounts[Customer][Banks];
        }
        
        if(temp > Richest)
        {
            Richest = temp;
        }
    }
    
    return Richest;
}