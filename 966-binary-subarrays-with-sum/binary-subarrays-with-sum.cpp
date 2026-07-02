class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count1(nums,goal)-count1(nums,goal-1);
    }
    int count1(vector<int>& nums,int goal){ //lesser than equal to goal
        if(goal<0) return 0;
        int n=nums.size();
        int left=0;
        int right=0;
        int sum=0;
        int count=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};