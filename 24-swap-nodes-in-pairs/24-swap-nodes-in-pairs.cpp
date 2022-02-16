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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* p=head,*c=head->next;
        head=head->next;
        ListNode* d;
        
        while(p->next)
        {
            p->next=c->next;
            c->next=p;
            d=p->next;
            if(d && d->next)
            {
                p->next=d->next;
                p=d;
                c=p->next;
            }else
            {
                break;
            }
        }
        
        return head;
        
        
    }
};