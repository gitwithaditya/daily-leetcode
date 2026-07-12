class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        // set<vector<int>> stt;
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         set<long long> hash;
        //         for(int k=j+1;k<n;k++){
        //             long long need=1LL*target-nums[i]-nums[j]-nums[k];
        //             if(hash.find(need)!=hash.end()){
        //                 vector<int> temp={nums[i],nums[j],nums[k],(int)need};
        //                 sort(temp.begin(),temp.end());
        //                 stt.insert(temp);
        //             }
        //             hash.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(stt.begin(),stt.end());
        // return ans;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long kk=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(kk<target) k++;
                    else if(kk>target)l--;
                    else{
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};