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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        int k1=1;
        ListNode* l1=head;
        ListNode* s1;
        
        while(l1!=NULL)
        {
            l1=l1->next;
            k1++;
            if(k1==k)
                s1=l1;
        }
    
        if(k1==2)
        {
            return head;
        }
        
        // cout<<s1->val;
        int k2 = 1;
        l1=head;
        ListNode* s2;
        
        while(l1!=NULL && k2!=(k1-1-k+1))
        {
            k2++;
            l1=l1->next;
        }
            
        int x = s1->val;
        s1->val = l1->val;
        l1->val = x;
        
        
        return head;
        
        
        
    }
};