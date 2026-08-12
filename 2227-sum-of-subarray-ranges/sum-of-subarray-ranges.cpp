class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //BRUTE FORCE
        int n=nums.size();
        long long total=0;
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                total+=(maxi-mini)*1LL;
            }
        }
        return total;
    }
};