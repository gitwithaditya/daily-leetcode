// class Solution {
// public:
//     vector<vector<int> > combinationSum3(int k, int n) {
//     	//your code goes here
//         vector<int>  nums={1,2,3,4,5,6,7,8,9};
//         vector<vector<int>> ans;
//         vector<int> temp;
//         func(nums,0,n,k,temp,ans);
//         return ans;
//     }

//     void func(vector<int>&nums, int index, int n, int k, vector<int>&temp, vector<vector<int>>&ans){
//     if(n==0){
//         if(temp.size()==k){
//             ans.push_back(temp);
//         }
//         return;
//     }
//         if(n<0 || index==nums.size()){
//             return;
//         }
//     //yes->
//     temp.push_back(nums[index]);
//     func(nums,index+1,n-nums[index],k,temp,ans);
//     temp.pop_back();

//     //no->
//     func(nums,index+1,n,k,temp,ans);
// }
// };

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	//your code goes here2.0
        vector<vector<int>> ans;
        vector<int> temp;
        func(n,k,1,temp,ans);
        return ans;
    }

    void func(int n, int k, int index, vector<int>& temp, vector<vector<int>>& ans){
        if(n==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        else if(n<0 || k<temp.size()){
            return;
        }
        for(int i=index;i<=9;i++){
            temp.push_back(i);
            func(n-i,k,i+1,temp,ans);
            temp.pop_back();
        }
    }
};