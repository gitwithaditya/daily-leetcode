class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //BRUTE APPROACH->
        // int n=nums.size();
        // int count;
        // for(int i=0;i<n;i++){
        //     count=1;
        //     for(int j=i+1;j<n;j++){
        //         if(count>k) break;
        //         if(nums[i]==nums[j]) return true;
        //         count++;
        //     }
        // }
        // return false;

        //better APPROACH->
        int n=nums.size();
        int right=0;
        map<int,int> mpp;
        while(right<n){
            if(mpp.find(nums[right])!=mpp.end()){
                int check=abs(mpp[nums[right]]-right);
                if(check<=k) return true;
            }
            mpp[nums[right]]=right;
            right++;
        }
        return false;
    }
};