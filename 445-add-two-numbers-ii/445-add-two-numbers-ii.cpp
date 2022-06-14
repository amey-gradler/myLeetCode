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
    
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* sHead = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return sHead;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> st1,st2;
        
        while(l1)
        {
            st1.push(l1->val);
            l1=l1->next;
        }
        
        while(l2)
        {
            st2.push(l2->val);
            l2=l2->next;
        }
        
        
        ListNode* d = new ListNode(-1);
        ListNode* temp = d;
        
        int c=0;
        
        while(!st1.empty() || !st2.empty() || c)
        {
            int sum=0;
            
            if(!st1.empty())
            {
                sum+=st1.top();
                st1.pop();
            }
            
            if(!st2.empty())
            {
                sum+=st2.top();
                st2.pop();
            }
            
            if(c)
            {
                sum+=c;
                c=0;
            }
            
            c=sum/10;
            sum=sum%10;
            
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp=temp->next;
            
        }
        
        return reverse(d->next);
        
        
        
    }
};