class Solution {
public:
    int characterReplacement(string s, int k) {
        // int n=s.size();
        // int maxlen=0;
        // for(int i=0;i<n;i++){
        //     int maxf=0;
        //     vector<int> hash(26,0);
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'A']++;
        //         maxf=max(maxf,hash[s[j]-'A']);
        //         int len=j-i+1;
        //         int changes=len-maxf;
        //         if(changes<=k){
        //             maxlen=max(maxlen,len);
        //         }
        //         else break;
        //     }
        // }
        // return maxlen;


        int n=s.size();
        int left=0;
        int right=0;
        int maxlen=0;
        int maxf=0;
        vector<int> hash(26,0);
        while(right<n){
            hash[s[right]-'A']++;
            maxf=max(maxf,hash[s[right]-'A']);
            int len=right-left+1;
            int changes=len-maxf;
            while(changes>k){
                hash[s[left]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++){
                    maxf=max(maxf,hash[i]);
                }
                left++;
                len=right-left+1;
                changes=len-maxf;
            }
            if(changes<=k){
                maxlen=max(maxlen,len);
            }
            right++;
        }
        return maxlen;
    }
};