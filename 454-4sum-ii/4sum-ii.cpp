class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mpp1;
        for(int a:nums1){
            for(int b:nums2){
                mpp1[a+b]++;
            }
        }
        int sum=0;
        for(int c:nums3){
            for(int d:nums4){
                if(mpp1.find(-(c+d))!=mpp1.end()){
                    sum+=mpp1[-(c+d)];
                }
            }
        }
        return sum;
    }
};