class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mini=INT_MAX;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                ans=nums[mid];
                low++;
                high--;
            }
            else if(nums[mid]>=nums[low]){
                ans=nums[low];
                low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
                ans=nums[mid];
                high=mid-1;
            }
            mini=min(mini,ans);
        }
        return mini;
    }
};