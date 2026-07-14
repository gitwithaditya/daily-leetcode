class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(create(i));
        }
        return ans;
    }
    vector<int> create(int row){
        long long res=1;
        vector<int> anss;
        anss.push_back(1);
        for(int i=1;i<row;i++){
            res=res*(row-i);
            res=res/i;
            anss.push_back(res);
        }
        return anss;
    }
};