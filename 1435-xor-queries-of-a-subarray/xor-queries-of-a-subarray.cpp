class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans;
        vector<int> prefix(arr.size(),0);
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        for(int i=0;i<n;i++){
            ans.push_back(function(prefix,queries[i]));
        }
        return ans;
    }
    int function(vector<int>& arr,vector<int>& temp){
        int left=temp[0];
        int right=temp[1];
        if(left==0 && right==0) return arr[0];
        if(left==0 && right!=0) return arr[right];
        int N=0;
        // help=0;
        // N=0;
        // help1=0;
        // if(left-1<0){
        //     if((left-1)%4==1) help=1;
        // else if((left-1)%4==2) help=left+1;
        // else if((left-1)%4==3) help=0;
        // else help=left;
        // }

        // if(right%4==1) help1=1;
        // else if(right%4==2) help1=left+1;
        // else if(right%4==3) help1=0;
        // else help1=left;
        
        // N=help^help1;
       if(left!=0){
         N=arr[left-1]^arr[right];
       }
        return N;
    }
};