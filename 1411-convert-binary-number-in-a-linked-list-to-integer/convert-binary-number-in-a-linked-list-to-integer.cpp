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
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        int ans=pow(2,count)-1;
        temp=head;
        int pos=0;
        while(temp){
            pos++;
            if(temp->val==0){
                ans-=pow(2,count-pos);
            }
            temp=temp->next;
        }
        return ans;
    }
};