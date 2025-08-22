#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, n) for (int i = 0; i < n; i++)
const int MAXN = 1e5+1;

// Si la criba[n] == 0 => n es primo
// si no criba[n] es el divisor mas grande de n
#define MAXP 100000	//no necesariamente primo
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
	for(int i = 2; i < MAXP+1; i++) if (!criba[i]) primos.push_back(i);
}

// O(sqrt(n))
// para buscar los divisores de un unico numero
vector<int> divisors(int n) {
    vector<int> div;
    for (int d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            div.push_back(d);
            div.push_back(n/d);
        }
        if (d*d == n) div.pop_back(); // para cuadrados perfectos
    }
    sort(div.begin(), div.end());
    return div;
}

// precalcular divisores
// O(MAXN * lg(MAXN))
void pre_div() {
    vector<int> sum_div;
    vector<int> divs[MAXN];
    forn(i, MAXN) for(int j = i; j < MAXN; j+=i) {
        sum_div[j] += i;
        divs[j].push_back(i);
    }
}

// factorizar en O(sqrt(n))
map<ll, ll> fact_sqrt(int n) {
    map<ll, ll> F;
    for (int p = 2; p * p <= n; p++) {
        while (n%p == 0) {
            F[p]++;
            n /= p;
        }
    }
    if (n > 1) F[n]++;
    return F;
}

// factoriza bien numeros hasta MAXP^2
// O (cant primos)
// esta se podría hacer con la otra criba
map<ll,ll> fact(ll n) {
	map<ll,ll> ret; // factor, cantidad de veces
	for(auto p : primos){
		while(!(n % p)){ // mientras no sea divisor?
			ret[p]++; //divisor found
			n /= p;
		}
	}
	if(n > 1) ret[n]++;
	return ret;
}

// factoriza bien numeros hasta MAXP
map<ll,ll> fact2(ll n){ //O (lg n)
	map<ll,ll> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}
