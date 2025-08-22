#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

vector<tuple<int,int,int>> abc;

bool comp( int a, int b){
    return get<2>(abc[a]) > get<2>(abc[b]);
}

set<int> used;

int solve(vector<vector<int>> &orden, int p){
    cout << orden[p].size() << endl;
    if(orden[p].size()==0) return 0;

    int i=0;
    while(i < orden[p].size()){
        if(used.find(orden[p][i])==used.end())break;
        i++;
    }
    if(i==orden[p].size())return 0;
    used.insert(orden[p][i]);
    int nuevo_p = ((p-get<1>(abc[orden[p][i]])) / get<0>(abc[orden[p][i]]));
    return max(solve(orden,p), solve(orden,nuevo_p) + get<2>(abc[orden[p][i]]) );
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, p;
    cin >> n >> p;

    
    forn(i,n){
        int a,b,c;
        cin >> a >> b >> c;
        abc.push_back({a,b,c});
    }
    vector<vector<int>> orden(p+1);
    for(int i=p; i>0; i--){
        vector<int> aux;
        forn(j, abc.size()){
            int num = i - get<1>(abc[j]);
            if(num<=0)continue;
            int den = num / get<0>(abc[j]);
            if(den<=0)continue;
            aux.push_back(j);
        }
        sort(aux.begin(),aux.end(), comp);
        orden[i]=aux;
    }

    cout << solve(orden, p) << endl;

    return 0;
}