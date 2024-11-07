#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& bilhetes) {
        unordered_map<string, vector<string>> grafo;
        
        for (auto& bilhete : bilhetes) {
            grafo[bilhete[0]].push_back(bilhete[1]);
        }
        
        for (auto& [origem, destinos] : grafo) {
            sort(destinos.rbegin(), destinos.rend());
        }
        
        vector<string> itinerario;
        dfs("JFK", grafo, itinerario);
        
        reverse(itinerario.begin(), itinerario.end());
        return itinerario;
    }
    
private:
    void dfs(const string& aeroporto, unordered_map<string, vector<string>>& grafo, vector<string>& itinerario) {
        while (!grafo[aeroporto].empty()) {
            string proximo = grafo[aeroporto].back();
            grafo[aeroporto].pop_back();
            dfs(proximo, grafo, itinerario);
        }
        itinerario.push_back(aeroporto);
    }
};
