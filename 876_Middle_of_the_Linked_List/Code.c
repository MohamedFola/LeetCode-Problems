/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* tempList = head;
    int counterList = 0;
    
    while(tempList != NULL)
    {
        counterList++;
        tempList = tempList->next;
    }
    
    tempList = head;
    counterList /= 2;
    
    while((counterList--) != 0)
    {
        tempList = tempList->next;
    }
    
    return tempList;
}

/*
Runtime: 7 ms, faster than 11.58% of C online submissions for Middle of the Linked List.
Memory Usage: 5.7 MB, less than 99.58% of C online submissions for Middle of the Linked List
*/


/****************************************************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* tempList = head;
    int counterList = 0;
    
    while(tempList != NULL)
    {
        counterList++;
        tempList = tempList->next;
    }
    
    tempList = head;
    
    for(int i = 0 ; i < (counterList / 2) ; i++)
    {
        tempList = tempList->next;
    }
    
    return tempList;
}

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Middle of the Linked List.
Memory Usage: 5.8 MB, less than 80.38% of C online submissions for Middle of the Linked List.
*/