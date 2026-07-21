class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    // int n=mat.size();
    // int m=mat[0].size();
    // int maxi=INT_MIN;
    // int row=-1;
    // int col=-1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(mat[i][j]>maxi){
    //             maxi=mat[i][j];
    //             row=i;
    //             col=j;
    //         }
    //     }
    // }
    // return {row,col};

    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=maximum(mat,n,mid);
        int left=mid-1>=0?mat[row][mid-1]:-1;
        int right=mid+1<m?mat[row][mid+1]:-1;
        if(mat[row][mid]>left && mat[row][mid]>right){return {row,mid};}
        else if(mat[row][mid]<left) high=mid-1;
        else if(mat[row][mid]<right) low=mid+1;
        }
    return {-1,-1};
    }

    int maximum(vector<vector<int>>& mat,int n, int col){
        int maxi=INT_MIN;
        int row=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                row=i;
            }
        }
        return row;
    }
};