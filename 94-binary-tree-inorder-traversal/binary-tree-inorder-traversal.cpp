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
//     vector<int> inorderTraversal(TreeNode* root) {
//         //USING MORRIS TRAVERSAL->
//         vector<int> ans;
//         while(root){
//             if(!root->left){
//                 ans.push_back(root->val);
//                 root=root->right;
//             }
//             else{
//                 TreeNode* curr=root->left;
//                 while(curr->right && curr->right!=root){
//                     curr=curr->right;
//                 }
//                 if(!curr->right){ //Not traversed
//                    curr->right=root;
//                    root=root->left;
//                 }
//                 else{
//                     curr->right=nullptr;
//                     ans.push_back(root->val);
//                     root=root->right;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//ITERATIVE APPROACH(STACK)->
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> s;
        stack<bool> visited;
        s.push(root);
        visited.push(0);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            bool flag=visited.top();
            visited.pop();

            if(flag==0){
                if(node->right){
                s.push(node->right);
                visited.push(0);
                }

                s.push(node);
                visited.push(1);

                if(node->left){
                s.push(node->left);
                visited.push(0);
                }
            }
            else{
                    ans.push_back(node->val);
                }
        }
        return ans;
    }
};