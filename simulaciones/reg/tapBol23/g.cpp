#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXP 100009	//no necesariamente primo
#define MAXN 100009	//no necesariamente primo
#define operacion(x, y) x+y
#define tipo int
typedef int Elem;//Elem de los elementos del arreglo
typedef int Alt;//Elem de la alteracion
const Elem neutro = 0; 
const Alt neutro2=-1;
struct RMQ{
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];//las alteraciones pueden ser de distinto Elem
	Elem &operator[](int p){return t[sz+p];}
	void init(int n){//O(nlgn)
		sz = 1 << (32-__builtin_clz(n));
		forn(i, 2*sz) t[i]=neutro;
		forn(i, 2*sz) dirty[i]=neutro2;
	}
    void updall(){
        dforn(i, sz) t[i] = operacion(t[2*i], t[2*i+1]);
    }
	void push(int n, int a, int b){//propaga el dirty a sus hijos
		if(dirty[n]!=-1){
			t[n]=dirty[n];//altera el nodo 
			if(n<sz){
				dirty[2*n]=dirty[n];
				dirty[2*n+1]=dirty[n];
			}
			dirty[n]=-1;
		}
	}
	Elem get(int i, int j, int n, int a, int b){//O(lgn)
		if(j<=a || i>=b) return neutro;
		push(n, a, b);//corrige el valor antes de usarlo
		if(i<=a && b<=j) return t[n];
		int c=(a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	Elem get(int i, int j){return get(i,j,1,0,sz);}
	//altera los valores en [i, j) con una alteracion de val
	void alterar(Alt val, int i, int j, int n, int a, int b){//O(lgn)
		push(n, a, b);
		if(j<=a || i>=b) return;
		if(i<=a && b<=j){
			dirty[n]=val;
			push(n, a, b);
			return;
		}
		int c=(a+b)/2;
		alterar(val, i, j, 2*n, a, c), alterar(val, i, j, 2*n+1, c, b);
		t[n]=operacion(t[2*n], t[2*n+1]);//por esto es el push de arriba
	}
	void alterar(Alt val, int i, int j){alterar(val,i,j,1,0,sz);}
}mx, v;

int criba[MAXP+1];
void crearcriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3; 
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p]) 
		for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}
vector<int> primos;
void buscarprimos(){
	crearcriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}

int sumfactores(int n){
    if(n == 1) return 0;
    int acum = 0;
    for(auto it : primos){
        while(n%it==0){
            n = n/it;
            acum += it;
        }
    }
    return acum;
}

int pmg[20015];

int main() {
    HOLA;
    #ifdef EBUG
    freopen("g.txt", "r", stdin);
    #endif
	buscarprimos();
    forr(i, 1, 20000){
        pmg[i] = 1;
        for(int it : primos){
            if(i < it) break;
            if(i % it == 0) pmg[i] = it;
        }
    }
    int n;
    cin >> n;
    mx.init(n);
    v.init(n);
    forn(i, n){
        int k;
        cin >> k;
        v[i] = k;
        mx[i] = sumfactores(k);
    }
    mx.updall();
    v.updall();
    int t;
    cin >> t;
    forn(i, t){
        /*
        forn(i, n){
            cout << mx.get(i, i+1) << " ";
        }cout << endl;
        */
        int k;
        cin >> k;
        if(k == 1){
            int num;
            cin >> num;
            int val = v.get(num-1, num);
            //cout << sumfactores(val/pmg[val]);
            mx.alterar(sumfactores(val/pmg[val]), num-1, num);
            v.alterar(val/pmg[val], num-1, num);
            //cout << endl;
        }
        if(k == 2){
            int l, r;
            cin >> l >> r;
            int val = mx.get(l-1, r);
            cout << val << endl;
        }

        if(k == 3){
            int l, r;
            int val;
            cin >> l >> r >> val;
            mx.alterar(sumfactores(val), l-1, r);
            v.alterar(val, l-1, r);

        }
    }
    return 0;
}