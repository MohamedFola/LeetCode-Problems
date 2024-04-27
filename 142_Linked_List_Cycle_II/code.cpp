#include<iostream>
#include<unordered_set>
#include<bits/stdc++.h>

using namespace std;


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        bool isCyclic = false;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { isCyclic = true; break; }
        }

        if (isCyclic)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            return fast;
        }
        
        return nullptr;
    }
};

int main()
{

    return 0;
}