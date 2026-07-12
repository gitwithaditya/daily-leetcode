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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        ListNode *temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        int k=cnt-n;
        ListNode *temp1=head;
        ListNode *prev=temp1;
        if(k==0){
            head=head->next;
            delete temp1;
            return head;
        }
        while(k){
            prev=temp1;
            temp1=temp1->next;
            k--;
        }
        prev->next=temp1->next;
        delete temp1;
        return head;
    }
};