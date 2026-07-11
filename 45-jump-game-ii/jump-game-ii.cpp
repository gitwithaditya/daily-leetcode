class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int jump=0;
        int maxindex=0;
        int limit=0;
        for(int i=0;i<nums.size()-1;i++){
            maxindex=max(maxindex,i+nums[i]);
            if(i==limit){
                jump++;
                limit=maxindex;
            }
            if(limit>=nums.size()-1){
               break;
            }
        }
         return jump;
    }
};