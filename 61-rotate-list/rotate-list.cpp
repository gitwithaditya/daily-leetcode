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
    ListNode* rotateRight(ListNode* head, int k) {
                if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        int count=1;
        while(temp->next){
            temp=temp->next;
            count++;
        }
        if(k%count==0) return head;
        k=k%count;
        int K=count-k;
        ListNode* kthnode=head;
        while(--K){
            kthnode=kthnode->next;
        }
        ListNode* newhead=kthnode->next;
        kthnode->next=NULL;
        temp->next=head;
        return newhead;
    }
};