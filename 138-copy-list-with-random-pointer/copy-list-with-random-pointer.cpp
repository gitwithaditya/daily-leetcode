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
    Node* copyRandomList(Node* head) {
        Node * temp=head;
        while(temp){
            Node * newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        temp=head;
        Node* newnode;
        while(temp){
            newnode=temp->next;
           if(temp->random!=NULL) newnode->random=temp->random->next;
           else newnode->random=NULL;
            temp=temp->next->next;
        }
        Node *dummynode=new Node(-1);
        Node *curr=dummynode;
        temp=head;
        while(temp){
            curr->next=temp->next;
            curr=curr->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        Node* ans=dummynode->next;
        delete dummynode;
        return ans;
    }
};