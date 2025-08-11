#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    tt=1;
    while(tt--){
        int k,n;
        cin >> k >> n;
        //rangos
        int minimo=0, maximo=0;
        forn(i,n){
            if(i%2==0)maximo++;
        }
        for(int i=1;i<n;i++){
            if((i-1)%3==0)minimo++;
        }
        if((n-1)%3==0)minimo++;
        if(k>maximo || k<minimo){
            cout << "*" << endl;
            return 0;
        }
        int ceros=0, simples=0, adelante=0, atras=0, dobles=0;
        ceros = n-k;
        //simples
        simples=k-1;
        ceros-=simples;
        //adelante
        if(ceros>0){
            ceros--;
            adelante=1;
        }
        //atras
        if(ceros>0){
            ceros--;
            atras=1;
        }
        //dobles
        dobles=ceros;
        simples-=dobles;

        string s(n, '0');
        if(adelante>0)s[0]='-';
        if(atras>0)s[n-1]='-';
        
        forn(i,n){
            if(s[i]!='0')continue;
            s[i]='X';
            if(dobles>0){
                s[i+1]='-';
                s[i+2]='-';
                dobles--;
            }else{
                if(simples>0){
                    s[i+1]='-';
                    simples--;
                }
            }
        }
        
        cout << s << endl;
    }

    return 0;
}