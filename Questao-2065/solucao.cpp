class Solution {
public:
    int maximalPathQuality(vector<int>& valores, vector<vector<int>>& arestas, int tempoMaximo) {
    unordered_map<int, vector<pair<int, int>>> grafo;
    for (const auto& aresta : arestas) {
        int u = aresta[0], v = aresta[1], tempo = aresta[2];
        grafo[u].emplace_back(v, tempo);
        grafo[v].emplace_back(u, tempo);
    }
    
    int qualidadeMaxima = 0;
    int n = valores.size();
    
    vector<int> visitado(n, 0);

    function<void(int, int, int)> dfs = [&](int no, int qualidadeAtual, int tempoAtual) {
        if (visitado[no] == 0) {
            qualidadeAtual += valores[no];
        }
        
        visitado[no]++;
        
        if (no == 0) {
            qualidadeMaxima = max(qualidadeMaxima, qualidadeAtual);
        }
        
        for (const auto& [vizinho, tempo] : grafo[no]) {
            if (tempoAtual + tempo <= tempoMaximo) {
                dfs(vizinho, qualidadeAtual, tempoAtual + tempo);
            }
        }
        
        visitado[no]--;
    };
    
    dfs(0, 0, 0);
    
    return qualidadeMaxima;
}
};