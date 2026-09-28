class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Creating adj list->
        int n=pairs.size(); //no. of edges
        unordered_map<int, int> In;
        unordered_map<int, int> Out;
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<n;i++){
            int u=pairs[i][0];
            int v=pairs[i][1];
            adj[u].push_back(v);

            Out[u]++;
            In[v]++;
        }

        //FINDING STARTING NODE
        int start=pairs[0][0];
        for(auto it:Out){
            int node=it.first;
            if(Out[node]-In[node]==1) start=node; //this is for euler path. euler circuit mai kisi bhi node se start krlo, thats why we give start=pairs[0][0];
        }

        vector<int> path;
        dfs(start,adj,path);

        reverse(path.begin(),path.end());
        vector<vector<int>> ans;
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }

    void dfs(int node,unordered_map<int, vector<int>>& adj, vector<int>& path){
            while(!adj[node].empty()){
                int neigh=adj[node].back();
                adj[node].pop_back();
                dfs(neigh,adj,path);
            }
            path.push_back(node);
        }
};