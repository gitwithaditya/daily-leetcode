class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //CREATING ADJ LIST->
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n,0);
        vector<int> low(n,0);
        vector<int> visited(n,0);
        vector<vector<int>> ans;
        int count=0;
        dfs(0,-1,count,adj,low,disc,ans,visited);
        return ans;
    }

    void dfs(int node, int parent,int count,vector<vector<int>>& adj,vector<int>& low, vector<int>& disc,vector<vector<int>>& ans,vector<int>& visited){
        visited[node]=1;
        low[node]=count;
        disc[node]=count;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];
            if(neigh==parent) continue;
            else if(visited[neigh]){
                low[node]=min(low[node],low[neigh]);
            }
            else{
                count++;
                dfs(neigh,node,count,adj,low,disc,ans,visited);
                if(disc[node]<low[neigh]){
                    //BRIDGE EXISTS->
                    ans.push_back({node,neigh});
                }
                low[node]=min(low[node],low[neigh]);
            }
        }
    }
};