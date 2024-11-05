class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n); 
        vector<vector<int>> ancestors(n); 

        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        
        for (int i = 0; i < n; ++i) {
            set<int> visited; 
            dfs(i, i, adj, ancestors, visited);
        }

        
        for (int i = 0; i < n; ++i) {
            sort(ancestors[i].begin(), ancestors[i].end());
        }

        return ancestors;
    }

private:
    void dfs(int source, int current, vector<vector<int>>& adj, vector<vector<int>>& ancestors, set<int>& visited) {
        for (int neighbor : adj[current]) {
            if (visited.count(neighbor) == 0) {
                ancestors[neighbor].push_back(source);
                visited.insert(neighbor);
                dfs(source, neighbor, adj, ancestors, visited);
            }
        }
    }
};