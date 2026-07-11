class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        //your code goes here
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        func(0,n,ans,temp);
        return ans;
    }
    void func(int row, int n, vector<vector<string>>& ans, vector<string>& temp){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(isPossible(row,col,temp,n)){
                temp[row][col]='Q';
                func(row+1,n,ans,temp);
                temp[row][col]='.';
            }
        }
    }
    bool isPossible(int row, int col, vector<string>& temp, int n){
        int r=row;
        int c=col;
        //checking for top
        while(r>=0){
            if(temp[r][c]=='Q') return false;
            r--;
        }

        //checking for upperleftdiagonal->
        r=row;
        c=col;
        while(r>=0 && c>=0){
            if(temp[r][c]=='Q') return false;
            r--;
            c--;
        }

        //checking for upperleftdiagonal->
        r=row;
        c=col;
        while(r>=0 && c<n){
            if(temp[r][c]=='Q') return false;
            r--;
            c++;
        }

        return true;
    }
};