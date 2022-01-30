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
        
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr->next!=NULL)
        {
            if(curr->val == curr->next->val)
            {
                while(curr->next!=NULL &&  curr->val == curr->next->val)
                    curr=curr->next;
                if(curr->next==NULL)
                {
                    if(prev)
                    {
                        prev->next=NULL;
                        return head;
                    }else
                    {
                        return NULL;
                    }
                }
                if(prev!=NULL)
                {
                    prev->next=curr->next;
                    curr=curr->next;
                }
                else
                {
                    head=curr->next;
                    curr=head;
                }
                continue;
            }
            prev=curr;
            curr=curr->next;
        }
        
        return head;
        
    }
};