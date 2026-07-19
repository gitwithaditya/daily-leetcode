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
    ListNode* middleNode(ListNode* head) {
         if(head==NULL) return head;
        ListNode *temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        ListNode *temp1=head;
        ListNode *prev=temp1;
        if(cnt%2==0){
            int k=(cnt+2)/2;
            while(k){
                prev=temp1;
                temp1=temp1->next;
                k--;
            }
        }
        else{
            int k=(cnt+1)/2;
            while(k){
                prev=temp1;
                temp1=temp1->next;
                k--;
            }
        }
        return prev;
    }
};