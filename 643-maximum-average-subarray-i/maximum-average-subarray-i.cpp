class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // int n=nums.size();
        // double maxi=-DBL_MAX;
        // for(int i=0;i<=n-k;i++){
        //     double ans=0.0;
        //     for(int j=i;j<(i+k);j++){
        //         ans+=nums[j];
        //     }
        //     maxi=max(maxi,ans);
        // }
        // return maxi/(double)k;


        //SLIDING WINDOW;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        long long maxi=sum;

        for(int i=k;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-k];
            maxi=max(maxi,sum);
        }
        return (double)maxi/k;
    }
};