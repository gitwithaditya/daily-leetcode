class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]<=nums[i-1]){
                sum=0;
            }
          sum+=nums[i];
          maxi=max(maxi,sum);
        }
        return maxi;
    }
};