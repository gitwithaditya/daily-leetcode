class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nn=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> hash(maxi+1,0);
        for(int i=0;i<nn;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]>1){
                return i;
                break;
            }
        }
        return -1;
        // map<int,int> mpp;
        // for(int i=0;i<nums.size();i++){
        //     if(mpp.find(nums[i])==mpp.end()){
        //     mpp[nums[i]]=i;
        //     }
        //     else return nums[i];
        // }
        // return -1;

    }
};