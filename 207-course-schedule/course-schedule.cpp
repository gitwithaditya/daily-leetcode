// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

//OR WE CAN SAY IF THE GRAPH IS CYCLIC / UNDIRECTED THEN RETURN FALSE OTHERWISE TRUE->(USING STACK/BACKTRACKING)

//         //creating adj list->
//         vector<vector<int>> adj(numCourses);
//         for(int i=0;i<prerequisites.size();i++){
//             int u=prerequisites[i][1];
//             int v=prerequisites[i][0];
//             adj[u].push_back(v);
//         }

//         vector<int> visited(numCourses,0);

//         for(int i=0;i<numCourses;i++){
//             if(!visited[i]){
//                 if(!dfs(i,adj,visited)){  //cycle detect
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }

//     bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
//         visited[node]=1;
//         for(int i=0;i<adj[node].size();i++){
//             if(visited[adj[node][i]]==1){
//                 return false; //cycle detect
//             }
//             if(visited[adj[node][i]==0]){
//                 if(!dfs(adj[node][i],adj,visited)){
//                     return false;
//                 }
//             }
//         }
//         visited[node]=2; //backtracking k time sare nodes ko 2 mark krdo
//         return true;
//     }
// };



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

// BASICALLY IF THE GRAPH IS DAG GRAPH THEN RETURN TURE, OTHERWISE FALSE->(BEACUSE DAG KA HI SIRRF TOPOLOGICAL SORT NIKALTA HAI)->(KAHN'S ALGO)

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }

        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                indegree[adj[node][i]]--;

                if (indegree[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }

        if (ans.size() != numCourses) {
            return false;
        }

        return true;
    }
};