class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        stack<int> st;
        map<int,int> mpp;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            mpp[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};