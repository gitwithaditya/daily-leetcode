class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {

        vector<vector<pair<int,int>>> adj(n);

        // RED = 0, BLUE = 1
        for(int i=0; i<redEdges.size(); i++){
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            adj[u].push_back({v,0});
        }

        for(int i=0; i<blueEdges.size(); i++){
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            adj[u].push_back({v,1});
        }

        vector<vector<int>> visited(n, vector<int>(2,0));

        // dist[node][color] = shortest distance reaching node
        // with last edge of this color
        vector<vector<int>> dist(n, vector<int>(2,INT_MAX));

        queue<pair<int,int>> q;

        // Starting node: no previous color
        q.push({0,0});
        q.push({0,1});

        dist[0][0] = 0;
        dist[0][1] = 0;

        visited[0][0] = 1;
        visited[0][1] = 1;

        while(!q.empty()){

            int node = q.front().first;
            int nodecol = q.front().second;
            q.pop();

            for(int i=0; i<adj[node].size(); i++){

                int neigh = adj[node][i].first;
                int color = adj[node][i].second;

                if(color != nodecol && !visited[neigh][color]){

                    visited[neigh][color] = 1;

                    dist[neigh][color] = dist[node][nodecol] + 1;

                    q.push({neigh,color});
                }
            }
        }

        vector<int> ans(n,-1);

        for(int i=0; i<n; i++){

            int d = min(dist[i][0],dist[i][1]);

            if(d != INT_MAX){
                ans[i] = d;
            }
        }

        return ans;
    }
};