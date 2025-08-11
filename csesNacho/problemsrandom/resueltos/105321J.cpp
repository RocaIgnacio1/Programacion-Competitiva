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
    
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    map<ll,int> occur;
    vector<pair<ll,int>> sumas, random;
    int mitades=0;
    forn(i,n){
        cin >> a[i];
        occur[a[i]]++;
    }
    bool ban=1;
    if(x%2==0){
        mitades=occur[x/2];
        ban=0;
    }
    for(auto i: occur){
        if(!ban && i.first==(x/2))continue;
        
        if(occur.find(abs(i.first-x))!=occur.end()){
            sumas.push_back(make_pair(i.first,i.second));
        }else{
            random.push_back(make_pair(i.first,i.second));
        }
    }

    vector<ll> ans;
    for(auto i: sumas){
        if(i.first >= ((x/2)+ban))break;
        while(i.second>0){
            ans.push_back(i.first);
            i.second--;
        }
    }
    for(auto i: random){
        while(i.second>0){
            ans.push_back(i.first);
            i.second--;
        }
    }
    
    reverse(sumas.begin(),sumas.end());
    for(auto i: sumas){
        if(i.first < (x/2)+ban)break;
        while(i.second>0){
            if(mitades>0){
                ans.push_back(x/2);
                mitades--;
            }
            ans.push_back(i.first);
            i.second--;
        }
    }
    if(mitades>0){
        ans.push_back(x/2);
        mitades--;
    }

   
    vector<ll> ans2;
    forn(i,ans.size()){
        if(mitades>0){
            ans2.push_back(x/2);
            ans2.push_back(ans[i]);
            mitades--;
        }else{
            ans2.push_back(ans[i]);
        }
    }
    while(mitades>0){
        ans2.push_back(x/2);
        mitades--;
    }
  
    //checkear
    bool rta=true;

    forn(i,ans2.size()-1){
        if(ans2[i]+ans2[i+1]==x){
            rta=false;
            break;
        }
    }
    
    if(rta){
        forn(i,ans2.size()){
            cout << ans2[i] << " ";
        }
        cout << endl;
    }else{
        cout << "*" << endl;
    }
    

    return 0;
}