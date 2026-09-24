class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //CREATING ADJ LIST->
        vector<vector<pair<int,int>>> adj(n);
        int mod = 1e9 + 7;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int> visited(n,0);
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;

       for(int i=0;i<n;i++){
         int node=-1;
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(!visited[i] && mini>dist[i]){
                mini=dist[i];
                node=i;
            }
        }
        if(node==-1) break; //distored graph
        visited[node]=1;


        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i].first] && dist[adj[node][i].first]>(dist[node] + adj[node][i].second)){
                dist[adj[node][i].first]=dist[node] + adj[node][i].second;
                ways[adj[node][i].first]=ways[node];
            }
            else if(!visited[adj[node][i].first] && dist[adj[node][i].first]==(dist[node] + adj[node][i].second)){
                ways[adj[node][i].first]=(ways[adj[node][i].first]+ways[node])%mod;
            }
        }
       }
       return ways[n-1];
    }
};