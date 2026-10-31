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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     int r=0;
    //     int l=0;
    //     find(root,l,r,0);
    //     vector<vector<pair<int,int>>> negi(abs(l)+1);
    //     vector<vector<pair<int,int>>> posi(r+1);
    //     queue<TreeNode*> q;
    //     q.push(root);

    //     queue<int> index;
    //     index.push(0);

    //     queue<int> level;
    //     level.push(0);

    //     while(!q.empty()){
    //         TreeNode* node=q.front();
    //         q.pop();

    //         int pos=index.front();
    //         index.pop();

    //         int lvl=level.front();
    //         level.pop();

    //         if(pos>=0){
    //             posi[pos].push_back({lvl,node->val});
    //         }
    //         else{
    //             negi[abs(pos)].push_back({lvl,node->val});
    //         }

    //         if(node->left){
    //             q.push(node->left);
    //             index.push(pos-1);
    //             level.push(lvl+1);
    //         }
    //         if(node->right){
    //             q.push(node->right);
    //             index.push(pos+1);
    //             level.push(lvl+1);
    //         }
    //     }

    //     vector<vector<int>> ans;

    //     for(int i=negi.size()-1;i>=1;i--){
    //         sort(negi[i].begin(),negi[i].end());

    //         vector<int> temp;
    //         for(int j=0;j<negi[i].size();j++){
    //             temp.push_back(negi[i][j].second);
    //         }
    //         ans.push_back(temp);
    //     }
    //     for(int i=0;i<posi.size();i++){
    //         sort(posi[i].begin(),posi[i].end());

    //         vector<int> temp;
    //         for(int j=0;j<posi[i].size();j++){
    //             temp.push_back(posi[i][j].second);
    //         }
    //         ans.push_back(temp);
    //     }
    //     return ans;
    // }
    // void find(TreeNode* root, int &l, int &r, int pos){
    //     if(root==nullptr) return;
    //     l=min(l,pos);
    //     r=max(r,pos);
    //     find(root->left,l,r,pos-1);
    //     find(root->right,l,r,pos+1);
    // }

    map<int,vector<pair<int,int>>> mpp; //mpp(idx,lvl,data)
        vector<vector<int>> ans;
        preorder(root,mpp,0,0);
        for(auto it=mpp.begin(); it!=mpp.end(); it++){
            sort(it->second.begin(),it->second.end());
            vector<int> temp;
            for(int j=0;j<it->second.size();j++){
                temp.push_back(it->second[j].second);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
    void preorder(TreeNode* root, map<int,vector<pair<int,int>>>& mpp, int idx, int lvl){
        if(!root) return;
        
        mpp[idx].push_back({lvl,root->val});
        preorder(root->left,mpp,idx-1,lvl+1);
        preorder(root->right,mpp,idx+1,lvl+1);
    }

};