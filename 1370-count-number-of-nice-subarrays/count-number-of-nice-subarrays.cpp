class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
    int count(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size();
        int count=0;
        int left=0;
        int right=0;
        int sum=0;
        while(right<n){
            sum+=nums[right]%2;
            while(sum>k){
                sum-=nums[left]%2;
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};