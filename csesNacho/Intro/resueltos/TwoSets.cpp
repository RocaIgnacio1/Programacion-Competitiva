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
    
    ll n; cin >> n;
    vector<int> set1;
    vector<int> set2;
    ll suma=0;
    for(int i=1; i<=n; i++)suma+=i;

    if(suma%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    suma=suma/2;
    cout<<"YES"<<endl;
    for(int i=n; i>0;i--){
        if(suma>=i){
            set1.push_back(i);
            suma-=i;
        }else{
            set2.push_back(i);
        }
    }
    cout<<set1.size()<<endl;
    forn(i,set1.size())cout<<set1[i]<<" ";
    cout<<endl;
    cout<<set2.size()<<endl;
    forn(i,set2.size())cout<<set2[i]<<" ";
    cout<<endl;

    return 0;
}