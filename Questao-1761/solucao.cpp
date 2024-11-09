#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        int minDegree = INT_MAX;
        bool found = false;
        
        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (adj[u].count(v)) {
                    for (int w : adj[u]) {
                        if (w != v && adj[v].count(w)) {
                            found = true;
                            int degree = adj[u].size() + adj[v].size() + adj[w].size() - 6;
                            minDegree = min(minDegree, degree);
                        }
                    }
                }
            }
        }
        
        return found ? minDegree : -1;
    }
};
