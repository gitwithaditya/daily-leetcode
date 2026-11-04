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
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        preorder(root1,leaf1);
        preorder(root2,leaf2);
        int size1=leaf1.size();
        int size2=leaf2.size();
        if(size1!=size2) return 0;
        else{
            for(int i=0;i<size1;i++){
                if(leaf1[i]!=leaf2[i]){
                    return 0;
                    break;
                }
            }
        }
        return 1;
    }
    void preorder(TreeNode* root, vector<int>&leaf){
        if(!root) return;
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }
        preorder(root->left,leaf);
        preorder(root->right,leaf);
    }
};