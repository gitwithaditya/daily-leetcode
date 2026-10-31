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
    vector<int> rightSideView(TreeNode* root) {
        map<int,vector<int>> mpp;
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(0);
        while(!q1.empty()){
            TreeNode* node=q1.front();
            int lvl=q2.front();
            q1.pop();
            q2.pop();
            mpp[lvl].push_back(node->val);
            if(node->left){
                q1.push(node->left);
                q2.push(lvl+1);
            }
            if(node->right){
                q1.push(node->right);
                q2.push(lvl+1);
            }
        }
        // for(int i=0;i<mpp.size();i++){
        //     int j=mpp[i].size()-1;
        //     ans.push_back(mpp[i][j]);
        // }  OR
        for(auto it=mpp.begin();it!=mpp.end();it++){
            ans.push_back(it->second.back());
        }
        return ans;
    }
};