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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL) return NULL;
        
        ListNode *prev1=NULL;
        ListNode *temp1=l1;
        ListNode *front1;
        while(temp1){
            front1=temp1->next;
            temp1->next=prev1;
            prev1=temp1;
            temp1=front1;
        }
        ListNode *prev2=NULL;
        ListNode *temp2=l2;
        ListNode *front2;
        while(temp2){
            front2=temp2->next;
            temp2->next=prev2;
            prev2=temp2;
            temp2=front2;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        int sum=0;
        int carry=0;
        while(prev1 || prev2){
            sum=carry;
            if(prev1){
                sum+=prev1->val;
            }
            if(prev2){
                sum+=prev2->val;
            }
            carry=sum/10;
            ListNode *newnode=new ListNode(sum%10);
            curr->next=newnode;
            curr=newnode;
            if(prev1) prev1=prev1->next;
            if(prev2) prev2=prev2->next;
        }
        if(carry){
            ListNode *newnode=new ListNode(carry);
            curr->next=newnode;
            curr=newnode;
        }
        ListNode* prev3=NULL;
        ListNode* temp3=dummy->next;
        ListNode* front3;
        while(temp3){
            front3=temp3->next;
            temp3->next=prev3;
            prev3=temp3;
            temp3=front3;
        }
        return prev3;
    }
};