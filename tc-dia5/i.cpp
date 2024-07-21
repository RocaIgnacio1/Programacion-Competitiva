#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define print()

int main(){
    //freopen("input.txt", "r", stdin);
    int n, k, m;
    vector<string> pal;
    vector<int> v;
    vector<vector<int>> g;
    map<int, int> group;
    vector<string> d;
    vector<int> valor_grupo;
    vector<pair<string, int>> dic_pos;
    cin >> n >> k >> m;
    forn(i, n){
        string s;
        cin >> s;
        d.push_back(s);
    }
    forn(i, n){
        int s;
        cin >> s;
        v.push_back(s);
    }
    forn(i,n){
        pair<string, int> a;
        a.first = d[i];
        a.second = i;
        dic_pos.push_back(a);
    }
    sort(dic_pos.begin(), dic_pos.end(), [](const pair<string,int>&a, const pair<string,int>&b){
        return a.first < b.first;
    });
    forn(i, k){
        int s;
        cin >> s;
        vector<int> aux;
        int maxl = 1E9 + 200;
        forn(j, s){
            int r;
            cin >> r;
            aux.push_back(r);
            maxl = min(v[r - 1], maxl);
            group[r - 1] = i;
        }
        valor_grupo.push_back(maxl);
        g.push_back(aux);
    }
    ll sum = 0;
    forn(i, m){
        string s;
        cin >> s;
        pal.push_back(s);
    }
    int con = 0;
    sort(pal.begin(), pal.end());
    forn(i, n){
        if(con < k && pal[con] == dic_pos[i].first){
            sum += valor_grupo[group[dic_pos[i].second]];
            con++;
            while(pal[con-1] == pal[con]){
                sum += valor_grupo[group[dic_pos[i].second]];
                con++;
            }
        }
    }
    cout << sum << endl;
}