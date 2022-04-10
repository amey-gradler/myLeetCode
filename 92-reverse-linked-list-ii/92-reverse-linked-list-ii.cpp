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
    
    ListNode* rev(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* shead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
    
        return shead;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* curr=head, *prev=NULL;
        ListNode* forw = head;
        int cnt=1;
        while(curr!=NULL and cnt!=left)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        cnt=1;
        while(forw!=NULL and cnt!=right)
        {
            forw=forw->next;
            cnt++;
        }
        ListNode* join = forw->next;
        
        forw->next=NULL;
        if(prev!=NULL)
            prev->next = rev(curr);
        else{
            head=rev(curr);
        }
        curr->next=join;
        return head;
        
        
    }
};