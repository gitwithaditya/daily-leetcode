// class Solution {
// public:
//     vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
//         //your code goes here
//         sort(candidates.begin(),candidates.end());
//         set<vector<int>> ans;
//         vector<int> temp;
//         func(candidates,0,target,temp,ans);
//         vector<vector<int>> anss;
//         for(auto i:ans){
//             anss.push_back(i);
//         }
//         return anss;
//     }

//     void func(vector<int>& candidates, int index, int target, vector<int>&temp, set<vector<int>>&ans){
//         if(target==0){
//             ans.insert(temp);
//             return;
//         }
//         if(target<0 || index==candidates.size()){
//             return;
//         }
//         //yes->
//         temp.push_back(candidates[index]);
//         func(candidates,index+1,target-candidates[index],temp,ans);
//         temp.pop_back();

//         //No->
//         func(candidates,index+1,target,temp,ans);
//     }
// };

// class Solution {
// public:
//     vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
//         //your code goes here
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>> ans;
//         vector<int> temp;
//         func(candidates,0,target,temp,ans);
//         return ans;
//     }

//     void func(vector<int>& candidates, int index, int target, vector<int>&temp, vector<vector<int>>&ans){
//         if(target==0){
//             ans.push_back(temp);
//             return;
//         }
//         if(target<0 || index==candidates.size()){
//             return;
//         }
//         //yes->
//         temp.push_back(candidates[index]);
//         func(candidates,index+1,target-candidates[index],temp,ans);
//         temp.pop_back();

//         //No->
//         for(int j=index+1;j<candidates.size();j++){
//             if(candidates[j]!=candidates[index]){
//               func(candidates,j,target,temp,ans);
//               break;
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(candidates,0,target,temp,ans);
        return ans;
    }

    void func(vector<int>& candidates, int index, int target, vector<int>&temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || index==candidates.size()){
            return;
        }
        //yes->
        temp.push_back(candidates[index]);
        func(candidates,index+1,target-candidates[index],temp,ans);
        temp.pop_back();

        //No->
        // for(int j=index+1;j<candidates.size();j++){
        //     if(candidates[j]!=candidates[index]){
        //       func(candidates,j,target,temp,ans);
        //       break;
        //     }
        // }

        for(int j=index+1;j<candidates.size();j++){
            if(candidates[j]==candidates[index]){
                continue;
            }
            else{
                 func(candidates,j,target,temp,ans);
                 break;
            }
        }
    }
};