class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // USING DFS

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        stack<int> st;
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, adj, st, visited)) {
                    return {};
                }
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    bool dfs(int node, vector<vector<int>>& adj,
             stack<int>& st, vector<int>& visited) {

        visited[node] = 1;

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];

            if (visited[neighbour] == 1) {
                return false;  // cycle detected
            }

            if (visited[neighbour] == 0) {
                if (!dfs(neighbour, adj, st, visited)) {
                    return false;
                }
            }
        }

        visited[node] = 2;
        st.push(node);

        return 1;
    }
};