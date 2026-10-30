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
    void recoverTree(TreeNode* root) {
        //1ST METHOD (O(N))->
    //     vector<int> in;
    //     inorder(root,in);
    //     int first=-1;
    //     int second=-1;
    //     int prev=-1;
    //     int present=-1;
    //     for(int i=0;i<in.size();i++){
    //         prev=present;
    //         present=i;
    //         if(prev!=-1 && in[prev]>in[present]){
    //             if(first==-1) first=prev;
    //             second=present;
    //         }
    //     }
    //     swap(in[first],in[second]);
        
    //     //UPDATING THE TREE->
    //     int idx=0;
    //     update(root,in,idx);
    // }
    // void inorder(TreeNode* root, vector<int>& in){
    //     if(!root) return;
    //     inorder(root->left,in);
    //     in.push_back(root->val);
    //     inorder(root->right,in);
    // }
    
    // void update(TreeNode*root, vector<int>& in, int &idx){
    //     if(!root) return;
        
    //     update(root->left,in,idx);
    //     root->val=in[idx++];
    //     update(root->right,in,idx);

    // 2ND METHOD MORRIS TRAVERSAL (O(1))->
    TreeNode* first,*second,*prev,*present;
    first=nullptr;
    second=nullptr;
    prev=nullptr;
    present=nullptr;
    
    while(root){
        //ROOT->LEFT EXISTS->
    if(!root->left){
        prev=present;
        present=root;
        if(prev && prev->val>present->val){
            if(!first) first=prev;
            second=present;
        }
        root=root->right;
    }
    
    //DOES EXISTS->
    else{
        TreeNode* curr=root->left;
        while(curr->right && curr->right!=root){
            curr=curr->right;
        }
        
        //NOT TRAVSERSED YET->
        if(!curr->right){
            curr->right=root;
            root=root->left;
        }
        //TRAVSERSED->
        else{
            curr->right=nullptr;
            prev=present;
        present=root;
        if(prev && prev->val>present->val){
            if(!first) first=prev;
            second=present;
        }
        root=root->right;
        }
    }
    }
    
    //SWAPPING VALUES->
    swap(first->val,second->val);

    }
};