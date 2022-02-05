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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        if(lists.empty())
        {
            return NULL;
        }
        
        int remaining = lists.size();
        while(remaining>1)
        {
            for(int i=0;i<remaining/2;i++)
            {
                auto merged = mergeTwo(lists[2*i],lists[2*i+1]);
                lists[i]=merged;
            }
            if(remaining%2 == 1) 
            {
            lists[remaining/2] = lists[remaining - 1];
            remaining = remaining/2+1;
            } 
            else 
            {
            remaining = remaining/2;
            }
        }
        
        return lists.front();
        
    }
    
    ListNode* mergeTwo(ListNode* L1 , ListNode* L2)
    {
        if(L1==NULL)
            return L2;
        if(L2==NULL)
            return L1;
        
        if(L1->val<=L2->val)
        {
            L1->next = mergeTwo(L1->next,L2);
            return L1;
        }
        else{
            L2->next = mergeTwo(L1,L2->next);
            return L2;
        }
        
        return L1;
    }
    
};