class Solution {
public:
    string minWindow(string s, string t) {
        //BRUTE APPROACH
        // int n=s.size();
        // int m=t.size();
        // int minlen=INT_MAX;
        // int sindex=-1;
        // for(int i=0;i<n;i++){
        //     vector<int> hash(256,0);
        //     for(int j=0;j<m;j++){
        //         hash[t[j]]++;
        //     }
        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         if(hash[s[j]]>0){
        //             hash[s[j]]--;
        //             count++;
        //         }
        //         if(count==m){
        //             int len=j-i+1;
        //             if(len<minlen){
        //                 minlen=len;
        //                 sindex=i;
        //             }
        //         }
        //     }
        // }
        // return sindex==-1?"":s.substr(sindex,minlen);

        //OPTIMAL APPROACH
        int n=s.size();
        int m=t.size();
        int minlen=INT_MAX;
        int sindex=-1;
        int left=0;
        int right=0;
        vector<int> hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int count=0;
        while(right<n){
            if(hash[s[right]]>0){
                count++;
            }
            hash[s[right]]--;
            while(count==m){
                int len=right-left+1;
                if(len<minlen){
                    minlen=len;
                    sindex=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};