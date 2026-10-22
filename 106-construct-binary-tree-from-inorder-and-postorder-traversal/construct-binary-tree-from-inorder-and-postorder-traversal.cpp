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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return tree(inorder, postorder,0,inorder.size()-1,postorder.size()-1);
    }

    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int index){
        if(instart>inend) return nullptr;
        TreeNode* root=new TreeNode(postorder[index]);
        int pos=find(inorder, postorder[index], instart, inend);
        root->left=tree(inorder, postorder, instart, pos-1, index-(inend-pos)-1);
        root->right=tree(inorder, postorder, pos+1, inend, index-1);
        return root;
    }
    int find(vector<int>& inorder, int target, int start, int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
};