class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //BRUTE FORCE
    //     int n=nums.size();
    //     long long total=0;
    //     for(int i=0;i<n;i++){
    //         int maxi=INT_MIN;
    //         int mini=INT_MAX;
    //         for(int j=i;j<n;j++){
    //             maxi=max(maxi,nums[j]);
    //             mini=min(mini,nums[j]);
    //             total+=(maxi-mini)*1LL;
    //         }
    //     }
    //     return total;

    //OPTIMAL APPROACH->
    int n=nums.size();
    return (totalmax(nums)-totalmin(nums));
    }

    long long totalmin(vector<int>& nums){
        int n=nums.size();
        vector<int> nse=findNSE(nums);
        vector<int> pse=findPSE(nums);
        long long total=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            total=(total+(right*left)*nums[i]);
        }
        return total;
    }

    long long totalmax(vector<int>& nums){
        int n=nums.size();
        vector<int> nge=findNGE(nums);
        vector<int> pge=findPGE(nums);
        long long total=0;
        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            total=(total+(right*left)*nums[i]);
        }
        return total;
    }


    vector<int> findNSE(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> findPSE(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> findPGE(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }



    vector<int> findNGE(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
};