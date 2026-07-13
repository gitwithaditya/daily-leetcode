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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(head==nullptr) return head;
        int k=right-left+1;
        ListNode *temp,*prev,*front,*previous,*track;
        temp=head;
        prev=nullptr;
        previous=nullptr;
        int l=left;
        while(--left){
            previous=temp;
            temp=temp->next;
        }
        track=temp;
        while(k){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
            k--;
        }
        if(l!=1){
            previous->next=prev;
        }
        else{
            head=prev;
        }
        track->next=temp;
        return head;
    }
};