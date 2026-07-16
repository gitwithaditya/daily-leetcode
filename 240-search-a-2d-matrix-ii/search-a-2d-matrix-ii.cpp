class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m=nums.size();
        int n=nums[0].size();
        int row=0;
        int col=n-1;
        while(row<m && col>=0){
            if(nums[row][col]==target) return true;
            else if(nums[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};