class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> temp;
        vector<int> temp1;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) temp.push_back(nums[i]);
            else{
                temp1.push_back(nums[i]);
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            nums[2*i]=temp1[i];
        }
        for(int i=0;i<cnt;i++){
            nums[(2*i)+1]=temp[i];
        }
        return nums;
    }
};