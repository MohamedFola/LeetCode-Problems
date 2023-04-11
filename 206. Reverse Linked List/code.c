/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode list;
list* reverseList(list* head)
{
    list* prev = NULL;
    list* temp = NULL;
    list* current = head;

    while ( current != NULL )
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}