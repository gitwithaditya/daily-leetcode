//USING BFS->
// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int> colored(n,-1);
//         for(int j=0;j<n;j++){
//             if(colored[j]==-1){ //unvisited node
//                 queue<int>q;
//         q.push(j);
//         colored[j]=0;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(int i=0;i<graph[node].size();i++){
//                 if(colored[graph[node][i]]==-1){
//                     colored[graph[node][i]]=(colored[node]+1)%2;
//                     q.push(graph[node][i]);
//                 }
//                 else{
//                     if(colored[graph[node][i]]==colored[node]){
//                         return 0;
//                     }
//                 }
//             }
//         }
//             }
//         }
//         return 1;
//     }
// };


//USING DFS->
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colored(n,-1);
        for(int i=0;i<n;i++){
            if(colored[i]==-1){
                colored[i]=0;
                if(!dfs(i,graph,colored)){
                    return false;
                }
            }
        }
        return true;
    }


    bool dfs(int node, vector<vector<int>>& adj, vector<int>& colored){
        for(int i=0;i<adj[node].size();i++){
             if(colored[adj[node][i]]==-1){
                colored[adj[node][i]]=(colored[node]+1)%2;
                if(!dfs(adj[node][i],adj,colored)) return false;
            }
            else{
                if(colored[adj[node][i]]==colored[node]) return false;
            }
        }
        return true;
    }
};