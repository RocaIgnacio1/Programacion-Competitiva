#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;
const ll MAXN = 10000000000;
 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    int t;
    cin >> t;
    forn(k,t){
        int n;
        cin >> n;
        vector<pair<char,int>> direc;
        vector<pair<char,int>> res;
        forn(i,n){
            char a;
            int x;
            cin >> a >> x;
            direc.push_back(make_pair(a,x));
        }

        int c;
        forn(i,n){
            if(i==0){
                res.push_back(make_pair('Z',direc[i].second));
            }else{
                char ant = direc[i-1].first;
                char neww = direc[i].first;
                if(ant == 'N' && neww=='E')res.push_back(make_pair('R',0));
                if(ant == 'N' && neww=='W')res.push_back(make_pair('L',0));
                if(ant == 'S' && neww=='W')res.push_back(make_pair('R',0));
                if(ant == 'S' && neww=='E')res.push_back(make_pair('L',0));

                if(ant == 'E' && neww=='S')res.push_back(make_pair('R',0));
                if(ant == 'E' && neww=='N')res.push_back(make_pair('L',0));
                if(ant == 'W' && neww=='S')res.push_back(make_pair('L',0));
                if(ant == 'W' && neww=='N')res.push_back(make_pair('R',0));
                res.push_back(make_pair('Z',direc[i].second));

            }

            
        }

        cout << res.size() << " " << direc[0].first << endl;

        forn(i,res.size()){
            if(res[i].second==0){
                cout << res[i].first << endl;
            }else{
                cout << res[i].first << " " << res[i].second << endl;
            }
        }        
    }
   
    return 0;
}
