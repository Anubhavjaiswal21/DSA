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
    ListNode* reverse(ListNode* headnode)
    {
        if(headnode==NULL || headnode->next==NULL)
        return headnode;
        ListNode* newHead=reverse(headnode->next);
        ListNode* front=headnode->next;
        front->next=headnode;
        headnode->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* head2=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=head2;
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                reverse(slow->next);
                return false;
            }
            first=first->next;
            second=second->next;

        }
        reverse(slow->next);
        return true;
    }
};