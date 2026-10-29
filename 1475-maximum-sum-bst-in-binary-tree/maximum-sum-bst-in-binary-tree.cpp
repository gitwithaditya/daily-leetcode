/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Box {
    public:
    bool BST;
    long long sum;
    long long max;
    long long min;
    Box(){
        BST=1;
        sum=0;
        max=LLONG_MIN;
        min=LLONG_MAX;
    }
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        long long totalsize=0;
        find(root, totalsize);
        return (int)totalsize;
    }
    Box* find(TreeNode* root, long long& totalsum){
        //ROOT DOESN'T EXTSTS->
        if(!root){
            return new Box();
        }
        //ROOT DOES EXISTS->
        Box* leftHead=find(root->left, totalsum);
        Box* rightHead=find(root->right, totalsum);
        if(leftHead->BST && rightHead->BST && root->val>leftHead->max && root->val<rightHead->min){
            Box* head=new Box();
            //Update the Box->
            head->sum=root->val+leftHead->sum+rightHead->sum;
            head->min=min(leftHead->min,(long long)root->val);
            head->max=max(rightHead->max,(long long)root->val);
            totalsum=max(totalsum,head->sum);
            return head;
        }
        else{
            leftHead->BST=0;
            return leftHead;
        }
    }
};