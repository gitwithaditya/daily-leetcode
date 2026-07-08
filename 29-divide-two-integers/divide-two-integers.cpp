class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        //your code goes here
        long long n=llabs(dividend);
        long long d=llabs(divisor);
        bool sign=true;
        if(dividend<0 && divisor>0) sign=false;
        if(dividend>0 && divisor<0) sign=false;
        long long ans=0;
        int cnt;
        while(n>=d){
            cnt=0;
            while(n>=d<<(cnt+1)){
                cnt++;
            }
            ans+=1LL<<cnt;
            n-=d<<cnt;
        }
        if(sign){
            if(ans>INT_MAX) return INT_MAX;
            else return ans;
        }
        else{
            if(ans>INT_MAX) return INT_MIN;
            else return -1*ans;
        }
    }
};