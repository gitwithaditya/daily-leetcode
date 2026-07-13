// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         set<vector<int>> ans;
//         vector<int> temp;
//         func(nums, 0, temp, ans);
//         //converting to vector->
//         vector<vector<int>> anss;
//         for(auto i:ans){
//             anss.push_back(i);
//         }

//         return anss;

//     }

//         void func(vector<int>&nums, int index, vector<int>& temp, set<vector<int>>& ans){
//             if(index==nums.size()){
//                 ans.insert(temp);
//                 return;
//             }

//             //yes->
//             temp.push_back(nums[index]);
//             func(nums,index+1,temp,ans);
//             temp.pop_back();

//             //No->
//             func(nums,index+1,temp,ans);

//     }
// };

class Solution {
public:
   map< vector<int> , int> mp ;
   vector<vector<int>>ans ;
   void solve(vector<int>&nums , int i, int n ,vector<int>&temp){
     if(i==n){
        if(mp.find(temp)==mp.end()){
            ans.push_back(temp) ;
            mp[temp] = 1  ;
        }
       
        return ;
     }
     temp.push_back(nums[i]) ;
     solve(nums , i+1 , n , temp) ;
     temp.pop_back() ;
     solve(nums , i+1 , n , temp) ;
   }
 
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        //your code goes here
        vector<int> temp ;
        solve(nums , 0 , nums.size() , temp) ;
        sort(ans.begin() , ans.end()) ;
        return ans ;
    }
};