class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
    int n=arr2.size();
    int left=0;
    int right=0;
    int count=0;
    int ind1=(m+n)/2;
    int ind2=(m+n)/2 - 1;
    int ans1;
    int ans2;
    while(left<m && right<n){
        if(arr1[left]<arr2[right]){
            if(ind1==count) ans1=arr1[left];
            if(ind2==count) ans2=arr1[left];
            count++;
            left++;
        }
        else{
            if(ind1==count) ans1=arr2[right];
            if(ind2==count) ans2=arr2[right];
            count++;
            right++;
        }
    }
    while(left<m){
    if(ind1==count) ans1=arr1[left];
    if(ind2==count) ans2=arr1[left];
    count++;
    left++;
    }

    while(right<n){
        if(ind1==count) ans1=arr2[right];
        if(ind2==count) ans2=arr2[right];
        count++;
        right++;
    }

    if((m+n)%2!=0) return (double)ans1;
    else{
        double ans=((double)ans1+ans2)/2;
        return ans;
    }
    }
};