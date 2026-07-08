class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        func(0,0,n,temp,ans);
        return ans;
    }
    void func(int left, int right, int n, string &temp, vector<string>&ans){
        if(left+right==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            func(left+1,right,n,temp,ans);
            temp.pop_back();
        }

        if(right<left){
            temp.push_back(')');
            func(left,right+1,n,temp,ans);
            temp.pop_back();
        }
    }
};

// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         //your code goes here
//         vector<string> list;
//         func(0,0,"",n,list);
//         return list;
//     }
//     void func(int open,int close,string s,int n,vector<string>& ans){
//         if(open>n) return;
//         if(open+close==2*n && open==close){
//             ans.push_back(s);
//             return;
//         }
//         func(open+1,close,s+'(',n,ans);
//         if(open>close){
//             func(open,close+1,s+')',n,ans);
//         }
//     }
// };