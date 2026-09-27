class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //CREATING ADJ LIST->
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }

        vector<int> dist(n+1,INT_MAX);
        vector<int> explored(n+1,0);
        dist[k]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            explored[node]=1;
            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i].first;
                int wt=adj[node][i].second;
                if(!explored[neigh] && dist[neigh]>d+wt){
                    dist[neigh]=wt+d;
                    pq.push({dist[neigh],neigh});
                }
            }
        }

        // return *max_element(dist.begin(),dist.end()); //0 bhi included hai uski value INT_MAX hai;
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            maxi=max(maxi,dist[i]);
        }
    return maxi;
    }
};