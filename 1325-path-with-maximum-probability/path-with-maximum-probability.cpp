class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //USING DJKSTRA'S ALGORITHM->

        //CREATING ADJ LIST->
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<double>dist(n,0.0);
        vector<int> explored(n,0);
        dist[start_node]=1.0;
        
        for(int i=0;i<n;i++){
            //finding maximum wt wala node->
        double maxi=0.0;
        int node=-1;
        for(int i=0;i<n;i++){
            if(!explored[i] && maxi<dist[i]){
                maxi=dist[i];
                node=i;
            }
        }
        if(node==-1) break; //Distorted graph k elements
        explored[node]=1;

        //RELAXING THE EDGES OF MAXIMUM NODE->
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i].first;
            double wt=adj[node][i].second;
            if(!explored[neigh] && dist[neigh]<(wt*dist[node])){
                dist[neigh]=wt*dist[node];
            }
        }
        }

        return dist[end_node];
    }
};