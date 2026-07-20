class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {\
    //BRUTE APPROACH->
        // int n=nums.size();
        // int maxlen=0;
        // int zero;
        // for(int i=0;i<n;i++){
        //     zero=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0) zero++;
        //         if(zero>k) break;
        //         int len=j-i+1;
        //         maxlen=max(maxlen,len);
        //     }
        // }
        // return maxlen;

        //OPTIMAL APPROACH->
        int n=nums.size();
        int left=0;
        int right=0;
        int maxlen=0;
        int zero=0;
        while(right<n){
            if(nums[right]==0) zero++;
            while(zero>k){
                if(nums[left]==0) zero--;
                left++;
            }
            int len=right-left+1;
            maxlen=max(maxlen,len);
            right++;
        }
        return maxlen;
    }
};