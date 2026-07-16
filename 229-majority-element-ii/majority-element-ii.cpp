class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || (n==2 && nums[0]!=nums[1]))
    return nums;
        if(n==2 && nums[0]==nums[1]) return {nums[0]};
        int count=1;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                count++;
                if(count==(n/3)+1){
                    ans.push_back(nums[i]);
                }
            }
            else count=1;
        }
        return ans;
    }
};