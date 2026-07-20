class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start>=arr.size() || start<0) return false;
        if(arr[start]==0) return true;
        if(arr[start]<0) return false;
        int jumplength=arr[start];
        arr[start]=-1;
        return(canReach(arr,start+jumplength)||canReach(arr,start-jumplength));
    }
};