/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast)
                break;
        }
        
        if(fast==NULL || fast->next==NULL)
        {
            return NULL;
        }
        else if(slow==fast)
        {
            slow=head;
            
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            
            return slow;
        }
        
        
        return NULL;
        
    }
};