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
    
    bool canRev(ListNode* temp,int k)
    {
        if(temp==NULL)
            return false;
        int cnt=1;
        while(temp!=NULL and cnt<=k)
        {
            temp=temp->next;
            cnt++;
        }
        
        if((cnt-1)!=k)
            return false;
        return true;
       
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return head;
        
        ListNode* curr=head;
        ListNode* prev=NULL, *temp;
        
        int cnt=1;
        while(curr!=NULL and cnt<=k)
        {
            temp=curr->next;
            curr->next=prev;
            prev= curr;
            curr=temp;
            cnt++;
        }
        
        if(temp!=NULL and canRev(temp,k))
            head->next = reverseKGroup(temp,k);
        else
            head->next = temp;
        
        return prev;
    }
};