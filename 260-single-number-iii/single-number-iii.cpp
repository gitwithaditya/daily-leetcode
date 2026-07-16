class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
                    map<int,int> mpp;
            for(int i=0;i<nums.size();i++){
                mpp[nums[i]]++;
            }
            vector<int> ans;
            for(auto itr:mpp){
                if(itr.second==1){
                    ans.push_back(itr.first);
                }
            }
            return ans;
    }
};