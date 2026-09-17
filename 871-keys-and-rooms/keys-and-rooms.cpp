class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& room) {
        int n=room.size();
        vector<int> visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<room[node].size();i++){
                if(visited[room[node][i]]==0){
                    visited[room[node][i]]=1;
                    q.push(room[node][i]);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};