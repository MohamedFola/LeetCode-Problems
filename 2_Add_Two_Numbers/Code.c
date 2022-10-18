
struct ListNode* createNode(int Copy_intValue)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));    // Create New Node
    newNode->val             = Copy_intValue;                          // Assign Value to the Node
    newNode->next            = NULL;                                   // Make the Node Points to NULL
    return newNode;                                             // return the Address of that Node
}


void insertAtEnd(int data, struct ListNode** head){
    struct ListNode* temp = *head;
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val  = data;
    newNode->next = NULL;

    if(temp==NULL){
        *head = newNode;
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* Local_result = NULL;

    int Local_intCarry = 0;

    while(l1  || l2 || Local_intCarry)
    {
        if(l1)
        {
            Local_intCarry += l1->val;
            l1 = l1->next;
        }
        
        
        if(l2)
        {
            Local_intCarry += l2->val;
            l2 = l2->next;
        }

        insertAtEnd((Local_intCarry % 10), &Local_result);

        Local_intCarry /= 10;
    }

    return Local_result;
}