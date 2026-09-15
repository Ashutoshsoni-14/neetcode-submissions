class Solution {
public:
    bool dfs(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& edges){
        vis[src] = true;
        recPath[src] = true;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][1];
            int v = edges[i][0];
            if(src == u){
                if(!vis[v]){
                    if(dfs(v,vis,recPath,edges)) return true;
                }
                else if(recPath[v]) return true; // Back edge condition
            }
        }
        recPath[src] = false;
        return false;
    }
    void topo(int src, vector<bool>& vis, stack<int>& st, vector<vector<int>>& edges){
        vis[src] = true;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][1];
            int v = edges[i][0];
            if(src == u){
                if(!vis[v]) topo(v,vis,st,edges);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,edges)) return ans;
            }
        }
        
        stack<int> st;
        vis.assign(n,false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topo(i,vis,st,edges);
            }
        }

        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
