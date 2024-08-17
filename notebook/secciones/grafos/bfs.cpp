void bfs(int nodo){
    cola.push(nodo);
    
    while(!cola.empty()){
        Nodo actual = cola.front();
        cola.pop();

        for (int vecino : G[actual]) {
            if (!visited[vecino]) {
                visited[vecino] = true;
                cola.push(vecino);
            }
        }
    }
}
