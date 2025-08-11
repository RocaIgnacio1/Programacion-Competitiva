#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int n;
ll c=0;
map<char,int> back;
vector<string> ans;
void solve(string s){
    if(s.size()==n){
        c++;
        ans.push_back(s);
    }else{
        for(auto i: back){
            if(i.second<=0)continue;
            back[i.first]--;
            solve(s+i.first);
            back[i.first]++;
        }
    }
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string t;
    cin >> t;
    n=t.size();
    forn(i,n){
        back[t[i]]++;
    }
    string p="";
    solve(p);
    cout<<c<<endl;
    forn(i,c)cout<<ans[i]<<endl;
    return 0;
}