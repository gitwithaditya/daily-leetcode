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

 //MORRIS TRAVERSAL->
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         while(root){
//             if(root->left==nullptr){
//                 ans.push_back(root->val);
//                 root=root->right;
//             }
//             else{
//                 TreeNode* curr=root->left;
//                 while(curr->right && curr->right!=root){
//                     curr=curr->right;
//                 }
//                 if(curr->right==nullptr){
//                     ans.push_back(root->val);
//                     curr->right=root;
//                     root=root->left;
//                 }
//                 else{
//                     curr->right=nullptr;
//                     root=root->right;
//                 }
//             }
//         }
//         return ans;
//     }
// };


//USING ITERATIVE(STACK) APPROACH->
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();

            ans.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};