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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp=list1;
        ListNode *tempp;
        int x=a-1;
        // while(--x){
        //     temp=temp->next;
        // }
        int y=b;
        ListNode *temp1;
        // while(--y){
        //     temp1=temp1->next;
        // }
        while(temp){
            if(x==0){
                tempp=temp;
            }
            if(y==0){
                temp1=temp;
            }
            temp=temp->next;
            x--;
            y--;
        }
        ListNode *temp2=list2;
        while(temp2->next){
            temp2=temp2->next;
        }
        tempp->next=list2;
        temp2->next=temp1->next;
        return list1;
    }
};