#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000


void mostrar(vector<int> &p1, vector<int> &p2){
    forn(i,p1.size())cout<<p1[i]<<" ";
    cout<<endl;
    forn(i,p2.size())cout<<p2[i]<<" ";
    cout<<endl;
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    forn(k,t){
        int n,a,b;
        cin>>n>>a>>b;
        int c = n-(a+b);
        int n2=n-c;

        vector<int> p1, p2;
        forn(i,n2)p1.push_back(i+1);
         
        for(int i=(n2-min(a,b)+1); i<=n2; i++){
            p2.push_back(i);
        }
        for(int i=1; i<(n2-min(a,b)+1); i++){
            p2.push_back(i);
        }
        int ult = p1.size()+1;
        forn(i,c){
            p1.push_back(ult);
            p2.push_back(ult);
            ult++;
        }
        int a2=0,b2=0,c2=0;
        forn(i,n){
            if(p1[i]>p2[i])a2++;
            if(p2[i]>p1[i])b2++;
            if(p1[i]==p2[i])c2++;
        }
        if(max(a2,b2)!=max(a,b) || min(a2,b2)!=min(a,b)){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(a>b){
            mostrar(p1,p2);
        }else{
            mostrar(p2,p1);
        }
        
    }
   
    return 0;
}