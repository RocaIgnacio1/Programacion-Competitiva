void dfs(int nodo){
    if(visited[nodo]) return;
    visited[nodo] = true;

    for(auto it : G[nodo]){
        if(!visited[it]){ 
            // logic
        }
    }
}
