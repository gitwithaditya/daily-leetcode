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
    int pairSum(ListNode* head) {
        // map<int, int> mpp;
        // ListNode *temp=head;
        // int i=0;
        // int count=0;
        // while(temp){
        //     mpp[i]=temp->val;
        //     temp=temp->next;
        //     count++;
        //     i++;
        // }
        // int ans=0;
        // for(int i=0;i<count/2;i++){
        //     ans=max(ans,mpp[i]+mpp[count-1-i]);
        // }
        // return ans;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp=slow->next;
        ListNode *prev=NULL;
        ListNode *front;
        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        int ans=0;
        temp=head;
        while(prev){
           ans=max(ans,temp->val+prev->val);
           prev=prev->next;
           temp=temp->next;
        }
        return ans;
    }
};