class Solution {
public:
    int totalNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        return func(0,n,temp);
    }
    int func(int row, int n, vector<string>& temp){
        if(row==n){
            return 1;
        }
        int ans=0;
        for(int col=0;col<n;col++){
            if(isPossible(row,col,temp,n)){
                temp[row][col]='Q';
                ans+=func(row+1,n,temp);
                temp[row][col]='.';
            }
        }
        return ans;
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