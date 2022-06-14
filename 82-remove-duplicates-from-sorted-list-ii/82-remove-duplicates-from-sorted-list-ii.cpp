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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || head->next==NULL)
            return head;
        
        ListNode* d = new ListNode(-1);
        d->next=head;
        ListNode* prev;
        prev =d;
        ListNode* cur = head;
        
        while(cur!=NULL)
        {
            if(cur && cur->next && cur->val == cur->next->val)
            {
                while(cur->next!=NULL && cur->val == cur->next->val)
                {
                    cur=cur->next;
                }
                
                prev->next = cur->next;
                cur=cur->next;
                
            }
            else{
                prev=prev->next;
                cur=cur->next;
                
            }
        }
        return d->next;
        
        
        
    }
};