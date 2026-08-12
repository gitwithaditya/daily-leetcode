class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //BRUTE FORCE->
        // int n=arr.size();
        // long long total=0;
        // int mod=1e9 + 7;
        // for(int i=0;i<n;i++){
        //     int mini=INT_MAX;
        //     for(int j=i;j<n;j++){
        //         mini=min(mini,arr[j]);
        //         total=(total+mini)%mod;
        //     }
        // }
        // return total;

        //OPTIMAL APPROACH->
        int n=arr.size();
        int mod=1e9 + 7;
        vector<int> nse=findNSE(arr);
        vector<int> pse=findPSE(arr);
        long long total=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            total=(total+(right*left)%mod * arr[i])%mod;
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
};