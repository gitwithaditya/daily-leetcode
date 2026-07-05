class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k){
                return mid;
            }
            if(nums[mid]>=nums[low]){
                if(nums[low]<=k && nums[mid]>k){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<k && nums[high]>=k){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};