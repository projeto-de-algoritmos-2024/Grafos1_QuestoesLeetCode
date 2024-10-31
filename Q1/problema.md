# 1791. Encontre o centro do gráfico estelar

Existe um gráfico estrela não direcionado consistindo de nnós rotulados de 1a n. Um gráfico estrela é um gráfico onde há um nó central e exatamente n - 1 arestas que conectam o nó central com todos os outros nós.

Você recebe um array de inteiros 2D edgesonde cada um indica que há uma aresta entre os nós e . Retorna o centro do gráfico de estrela fornecido.edges[i] = [ui, vi] ui vi

![Grafo](star_graph.png)


Entrada: bordas = [[1,2],[2,3],[4,2]]
 Saída: 2
 Explicação: Conforme mostrado na figura acima, o nó 2 está conectado a todos os outros nós, então 2 é o centro.
Exemplo 2:

Entrada: arestas = [[1,2],[5,1],[1,3],[1,4]]
 Saída: 1
 

Restrições:

- 3 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 1 <= ui, vi <= n
- ui != vi
- O dado edges representa um gráfico de estrelas válido.