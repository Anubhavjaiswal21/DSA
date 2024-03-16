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
 ListNode* findknode(ListNode* ptr, int k)
 {
        k-=1;
        while(ptr!=NULL && k>0)
        {
            k--;
            ptr=ptr->next;
        }
        return ptr;
 }
 ListNode* reverse(ListNode* head)
 {
    if(head==NULL || head->next==NULL)
    return head;
    ListNode* newhead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
 }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* knode=NULL;
        while(temp!=NULL)
        {
            knode=findknode(temp,k);
            if(knode==NULL)
            {
                if(prev)
                {
                    prev->next=temp;
                }
                break;
            }
            ListNode* nextnode=knode->next;
            knode->next=NULL;
            reverse(temp);
            if(temp==head)
            {
                head=knode;
            }
            else
            {
                prev->next=knode;
            }
            prev=temp;
            temp=nextnode;
    }
         return head;
    }
};