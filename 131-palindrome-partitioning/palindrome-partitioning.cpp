class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(0,s,temp,ans);
        return ans;
    }

    void func(int index, string s, vector<string>&temp,vector<vector<string>>&ans){
        if(s.size()==index){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s.substr(index,i-index+1))){
                temp.push_back(s.substr(index,i-index+1));
                func(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }

    bool ispalindrome(string st){
        int left=0;
        int right=st.size()-1;
        if(st.size()==1) return true;
        else{
            while(left<right){
                if(st[left]!=st[right]){
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    }
};