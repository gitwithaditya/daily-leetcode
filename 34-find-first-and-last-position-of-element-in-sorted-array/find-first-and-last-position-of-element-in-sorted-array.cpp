class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // int ans1=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         ans1=i;
        //         break;
        //     }
        // }

        // int ans2=-1;
        // for(int i=nums.size()-1;i>=0;i--){
        //     if(nums[i]==target){
        //         ans2=i;
        //         break;
        //     }
        // }
        // return {ans1,ans2};

        int n=nums.size();
        int first=firstOccurence(nums, target, n);
        int last=lastOccurence(nums, target, n);
        return {first,last};
    }

    int firstOccurence(vector<int>& nums, int target, int n){
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first;
    }

        int lastOccurence(vector<int>& nums, int target, int n){
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return last;
    }
};