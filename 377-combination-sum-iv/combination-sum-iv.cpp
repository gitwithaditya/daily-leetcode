//TLE->
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//          return func(nums,0,target);
//     }

//     int func(vector<int>& nums, int index, int k){
//         if(k==0){
//             return 1;
//         }
//         if(k<0 || index==nums.size()){
//             return 0;
//         }

//         int path1=func(nums,0,k-nums[index]);
//         int path2=func(nums,index+1,k);

//         return path1+path2;
//     }
// };



//MEMORY LIMIT EXCEEDED->
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> temp;
//         vector<vector<int>> ans;
//         func(nums,temp,ans,0,target);
//         return ans.size();
//     }

//     void func(vector<int>& nums,vector<int>& temp, vector<vector<int>>& ans, int index, int k){
//         if(k==0){
//             ans.push_back(temp);
//             return;
//         }
//         if(k<0 || index==nums.size()){
//             return;
//         }

//         func(nums,temp,ans,0,k-nums[index]);
//         func(nums,temp,ans,index+1,k);

//     }
// };


// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//          return func(nums,target);
//     }

//     int func(vector<int>& nums, int k){
//         if(k==0){
//             return 1;
//         }
//         if(k<0){
//             return 0;
//         }

//         int path1=0;


//         for(int i=0;i<nums.size();i++){
//         path1+=func(nums,k-nums[i]);
//         }

//         return path1;
//     }
// };

class Solution {
public:
    vector<long long> dp;

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return solve(nums, target);
    }

    int solve(vector<int>& nums, int k) {
        if (k == 0) return 1;
        if (k < 0) return 0;
        if (dp[k] != -1) return dp[k];

        long long ways = 0;
        for (int x : nums) {
            ways += solve(nums, k - x);
        }

        return dp[k] = ways;
    }
};

