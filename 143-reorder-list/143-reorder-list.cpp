/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head)
    {
        if(!head || head->next==NULL)
            return head;
        
        ListNode* sHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return sHead;
        
    }
    
    void reorderList(ListNode* head) {
        
        //find middle
        
        ListNode* slow = head,*fast=head,*prev=NULL;
        
        while(fast->next && fast->next->next)
        {
            prev=slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        
       
            prev=slow;
            slow=slow->next;
            
        
        //reverse second half
        prev->next = reverse(slow);
        
        slow=prev->next;
        ListNode* cur = head;
        
        // while(cur)
        // {
        //     cout<<cur->val<<" ";
        //     cur=cur->next;
        // }
        // cur=head;
        prev->next=NULL;
        
        
        
        
         while(cur && slow){
            fast=slow->next;
            slow->next=cur->next;
            cur->next=slow;
            cur=slow->next;
            slow=fast;
        }
        
        if (cur && cur->next) cur->next->next = NULL;
        
    }
};