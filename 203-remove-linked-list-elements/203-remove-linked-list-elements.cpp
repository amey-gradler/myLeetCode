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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head || (head->val==val && head->next==NULL))
            return NULL;
        
        ListNode* d = new ListNode();
        d->next=head;
        
        ListNode* prev=d;
        ListNode* temp = head;

        while(temp!=NULL)
        {

            if(temp->val==val)
            {
                
                prev->next = temp->next;
                temp=temp->next;
                
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        
        return d->next;
        
        
    }
};