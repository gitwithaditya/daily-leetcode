class Solution {
public:
    int numberOfSubstrings(string s) {
        //BRUTE APPROACH
        // int n=s.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     vector<int> hash(3,-1);
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'a']=1;
        //         if(hash[0]==1 && hash[1]==1 && hash[2]==1){
        //             count+=n-j;
        //             break;
        //         }
        //     }
        // }
        // return count;

        int n=s.size();
        vector<int> hash(3,-1);
        int count=0;
        for(int i=0;i<n;i++){
            hash[s[i]-'a']=i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                count+=1+*min_element(hash.begin(),hash.end());
            }
        }
        return count;
    }
};