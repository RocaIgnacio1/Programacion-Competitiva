#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

ll pow(int i){
    if(i==0)return 1;
    return 10*pow(i-1);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int q;cin>>q;
    
    forn(j,q){
        ll k;
        cin>>k;
        ll pot=1, i=1, suma=0;
        vector<ll> digitos;
        digitos.push_back(0);
        while(true){
            digitos.push_back(9*pot*i);
            suma+=digitos.back();
            if(suma>k)break;
            pot*=10;
            i++;
        }
        k = k-(suma-digitos.back());
        ll num = pow(i-1)-1;
        if((k%i)==0){
            num+=(k/i);
            string s= to_string(num);
            cout << s[s.size()-1] << endl;
        }else{
            num+=(k/i)+1;
            string s= to_string(num);
            cout << s[(k%i)-1] << endl;
        }

    }

    return 0;
}

