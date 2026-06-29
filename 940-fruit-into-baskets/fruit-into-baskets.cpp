class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //MAXIMUM SUBSTRING WITH ATMOST 2 DISTINCT INTEGERS->

        //BRUTE->
        // int n=fruits.size();
        // int maxlen=INT_MIN;
        // map<int,int> mpp;
        // for(int i=0;i<n;i++){
        //     mpp.clear();
        //     for(int j=i;j<n;j++){
        //         mpp[fruits[j]]++;
        //         if(mpp.size()>2) break;
        //         int len=j-i+1;
        //         maxlen=max(maxlen,len);
        //     }
        // }
        // return maxlen;

        //BETTER->
        // int n=fruits.size();
        // int left=0;
        // int right=0;
        // int maxlen=INT_MIN;
        // map<int,int> mpp;
        // while(right<n){
        //     mpp[fruits[right]]++;
        //     while(mpp.size()>2){
        //         mpp[fruits[left]]--;
        //         if(mpp[fruits[left]]==0){
        //             mpp.erase(fruits[left]);
        //         }
        //         left++;
        //     }
        //     int len=right-left+1;
        //     maxlen=max(maxlen,len);
        //     right++;
        // }
        // return maxlen;


        //OPTIMAL->
        int n=fruits.size();
        int left=0;
        int right=0;
        int maxlen=INT_MIN;
        map<int,int> mpp;
        while(right<n){
            mpp[fruits[right]]++;
            if(mpp.size()>2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            int len=right-left+1;
            maxlen=max(maxlen,len);
            right++;
        }
        return maxlen;
    }
};