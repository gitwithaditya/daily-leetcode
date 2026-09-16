class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //creating adj list->
    //     vector<vector<int>> adj(numCourses);
    //     for(int i=0;i<prerequisites.size();i++){
    //         int u=prerequisites[i][1];
    //         int v=prerequisites[i][0];
    //         adj[u].push_back(v);
    //     }

    //     stack<int> st;
    //     vector<int> visited(numCourses,0);
    //     for(int i=0;i<numCourses;i++){
    //         if(!visited[i]){
    //             dfs(i,adj,st,visited);
    //         }
    //     }
    //     vector<int> ans;
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //         st.pop();
    //     }
    //     return ans;
    // }

    // void dfs(int node,vector<vector<int>>& adj,stack<int>& st,vector<int>& visited){
    //     visited[node]=1;
    //     for(int i=0;i<adj[node].size();i++){
    //         if(!visited[adj[node][i]]){
    //             dfs(adj[node][i],adj,st,visited);
    //         }
    //     }
    //     st.push(node);

    //creating adj list->
    vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }

        //Creating the indegree array of all the nodes
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        //Initializing the queue with all the nodes having 0 indegree.
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};