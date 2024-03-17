/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* insertcopynode(Node* head) {
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* copynode=new Node(temp->val);
        copynode->next=temp->next;
        temp->next=copynode;
        temp=temp->next->next;
    }
    return head;
}
Node* connectRandomPointer(Node* head) {
    Node* temp=head;
    while(temp!=NULL)
    {
    Node* copynode=temp->next;
    if(temp->random==NULL)
    copynode->random=NULL;
    else
    {
        copynode->random=temp->random->next;
    }
    temp=temp->next->next;
    }
    return head;
}
 Node* connectNextPointer(Node* head) {
    Node* temp=head;
    Node* dummynode=new Node(0);
    Node* res=dummynode;
    while(temp!=NULL)
    {
        res->next=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        res=res->next;
    }
    return dummynode->next;
 }

    Node* copyRandomList(Node* head) {
        insertcopynode(head);
        connectRandomPointer(head);
        Node* copyhead=connectNextPointer(head);
        return copyhead;
        
    }
};