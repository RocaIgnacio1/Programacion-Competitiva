#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;

stack<int> H[2];

int not_in(int a, int b){
    assert(a != b);
    if (a + b == 1) return 2;
    if (a + b == 2) return 1;
    if (a + b == 3) return 0;
    return -1;
}

// Meter el primer elemento de a en b
void insert(int a, int b){
    assert(a >= 0 && a < 3 && b >= 0 && b < 3);
    H[b].push(H[a].top()); H[a].pop();
}

// Mover 2 elementos de la torre a a la torre b manteniendo el orden
void move(int a, int b, int n){
    int c = not_in(a, b); 
    insert(a, c);
    insert(a, b);
    insert(c, b);
}

/*void solve(int n, int a, int b, int aux){*/
/*    if (n == 1) a -> b*/
/*    solve(n-1, a, aux, b);*/
/*    solve(n-1, aux, b, a);*/
/*}*/

void order(int n){
    if (n == 1) return;
    forn(i, n){
        
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cerr.tie(NULL);

    int n;
    forn(i, n){
        int p;
        cin >> p;
        H[0].push(p);
    }

    return 0;
}
