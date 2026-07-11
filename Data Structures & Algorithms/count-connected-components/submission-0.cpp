class Solution {
public:
    void dfs(int i , unordered_map<int , vector<int>>& adj,vector<bool> &vis){
        vis[i] = true;
        for(auto & ngbr : adj[i]){
            if(vis[ngbr] == false){
                dfs(ngbr,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        vector<bool>vis(n,false);
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int result = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == false){
                dfs(i,adj,vis);
                result++;
            }
        }
        return result;
    }
};
