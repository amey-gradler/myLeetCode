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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* d1 = new ListNode(-1);
        ListNode* d2 = new ListNode(-2);
        
        ListNode* temp1,*temp2;
        temp1=d1;
        temp2=d2;
        
        ListNode* cur= head;
        
        while(cur!=NULL)
        {
            
            if(cur->val<x)
            {
                temp1->next=cur;
                temp1=cur;
                cur=cur->next;
                // temp1->next=NULL;
            }
            else{
                temp2->next=cur;
                temp2=cur;
                cur=cur->next;
                // temp2->next=NULL;
            }
            
        }
        temp1->next=NULL;
        temp2->next =NULL;
        temp1->next = d2->next;
        return d1->next;
        
        
        
    }
};