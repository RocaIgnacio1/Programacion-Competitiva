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
    
    string s;
    cin>>s;
    bool ban=true;
    if(s.size()==1){
        cout<<s<<endl;return 0;
    }
    if(s.size()%2==0){
        ban=false;
    }
    map<char,int> p;
    forn(i,s.size()){
        p[s[i]]++;
    }
    deque<char> ans;
    int suma=0;
    
    char repetido;
    for(auto i:p){
        if(i.second%2!=0){
            suma++;
            repetido=i.first;
            int c=i.second;

            for(int j=c; j>1; j=j-2){
                ans.push_back(i.first);
                ans.push_front(i.first);
            }
            continue;
        }
        int c=i.second;   
        for(int j=c; j>0; j=j-2){
            ans.push_back(i.first);
            ans.push_front(i.first);
        }
    }
    if((suma>0 && !ban) || (suma>1 && ban)){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    forn(i,ans.size()){
        if(i==(s.size()/2) && suma==1)cout<<repetido;
        cout<<ans[i];
    }
    

    return 0;
}