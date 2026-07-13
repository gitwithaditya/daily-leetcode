class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n=mat.size();
        bool ans=false;
        for(int i=0;i<n;i++){
            if(searching(mat[i],target)){
                ans=true;
            }
        }
        return ans;
    }

    bool searching(vector<int>&nums, int target){
        int n=nums.size();
        int high=n-1;
        int low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};