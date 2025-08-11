#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 1000001
const ll MOD = 1000000007;

ll comb[100][100];
ll lucas (ll n, ll k, int p){ //Calcula (n,k)%p teniendo comb[p][p] precalculado.
	ll aux = 1;
	while (n + k) aux = (aux * comb[n%p][k%p]) %p, n/=p, k/=p;
	return aux;
}
    

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    forn(z,n){
        int a,b;
        cin>>a>>b;
        
        forr(i,MOD-1,MOD){//comb[i][k]=i tomados de a k
            comb[i][0]=comb[i][i]=1;
            forr(k, 1, i) comb[i][k]=(comb[i-1][k]+comb[i-1][k-1])%MOD;
        }
        cout<<lucas(a,b,MOD)<<endl;
    }
    
    return 0;
}