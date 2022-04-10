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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *po=head;
        ListNode *pe=head->next;
        ListNode* peh = head->next;
        ListNode *curr=pe->next;
        pe->next=NULL;
        bool isOdd = true;
        
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            if(isOdd)
            {
                po->next = curr;
                po=po->next;
                po->next=peh;
                isOdd = false;
            }
            else
            {
                pe->next= curr;
                pe=pe->next;
                pe->next=NULL;
                isOdd = true;
            }
            curr=temp;
        }
        return head;
        
    }
};