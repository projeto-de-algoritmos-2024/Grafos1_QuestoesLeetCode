#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false); 
        int longestCycleLength = -1; 

        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_map<int, int> nodeIndex; 
                int index = 0;
                int current = i;

                
                while (current != -1 && !visited[current]) {
                    visited[current] = true;
                    nodeIndex[current] = index++;
                    current = edges[current];
                }

                
                if (current != -1 && nodeIndex.count(current)) {
                    int cycleLength = index - nodeIndex[current];
                    longestCycleLength = max(longestCycleLength, cycleLength);
                }
            }
        }

        return longestCycleLength;
    }
};
