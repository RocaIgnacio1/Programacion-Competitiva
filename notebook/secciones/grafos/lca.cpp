const int MAXN = 300001;
const int LOGN = 20;

vector<int> G[MAXN];
int N, f[MAXN][LOGN], L[MAXN]; // f[v][k] = 2^k-ésimo padre de v, L[v] = profundidad

// DFS para inicializar padres directos y profundidades
void dfs(int v, int fa = -1, int lvl = 0) {
    f[v][0] = fa;
    L[v] = lvl;
    for (int u : G[v]) {
        if (u != fa) dfs(u, v, lvl + 1);
    }
}

// Construcción de tabla de ancestros binarios
void build() {
    for (int k = 0; k < LOGN - 1; k++) {
        for (int i = 0; i < N; i++) {
            if (f[i][k] == -1) f[i][k + 1] = -1;
            else f[i][k + 1] = f[f[i][k]][k];
        }
    }
}

// log2 floor
#define lg(x) (31 - __builtin_clz(x))

// Subir d niveles desde el nodo a
int climb(int a, int d) {
    if (d > L[a]) return -1; // no existe tal ancestro
    for (int i = LOGN - 1; i >= 0; i--) {
        if ((1 << i) <= d && a != -1) {
            a = f[a][i];
            d -= 1 << i;
        }
    }
    return a;
}

// Lowest Common Ancestor (LCA)
int lca(int a, int b) {
    if (L[a] < L[b]) swap(a, b);
    a = climb(a, L[a] - L[b]);
    if (a == b) return a;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}

// Distancia entre dos nodos
int dist(int a, int b) {
    return L[a] + L[b] - 2 * L[lca(a, b)];
}