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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(root->right==nullptr){
                ans.push_back(root->val);
                root=root->left;
            }
            else{
                TreeNode* curr=root->right;
                while(curr->left && curr->left != root){
                    curr=curr->left;
                }
                if(curr->left==nullptr){
                    curr->left=root;
                    ans.push_back(root->val);
                    root=root->right;
                }
                else{
                    curr->left=nullptr;
                    root=root->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};