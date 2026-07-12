class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mapping[]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string temp="";
        func(mapping,0,digits,temp,ans);
        return ans;
    }

    void func(string mapping[],int index,string digit,string &temp,vector<string>&ans){
        if(index>=digit.size()){
            ans.push_back(temp);
            return;
        }

        int number=digit[index]-'0';
        string fahh=mapping[number];

        for(int i=0;i<fahh.size();i++){
            temp.push_back(fahh[i]);
            func(mapping,index+1,digit,temp,ans);
            temp.pop_back();
        }
    }
};