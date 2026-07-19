class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        vector<int> temp;
        vector<int> temp1;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) temp.push_back(nums[i]);
            else{
                temp1.push_back(nums[i]);
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            nums[i]=temp1[i];
        }
        for(int i=cnt;i<n;i++){
            nums[i]=temp[i-cnt];
        }
        return nums;
    }
};