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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head or head->next==NULL)
            return NULL;
        
        int cnt=0;
        ListNode* cur=head,*forw=head,*prev=NULL;
        
        while(forw)
        {
            if(cnt>=n)
            {
                prev=cur;
                cur=cur->next;
            }
            forw=forw->next;
            cnt++;
        }
        
        if(prev)
        {
            prev->next=cur->next;
        }
        else{
            head=cur->next;
        }
        
        return head;
        
        
    }
};