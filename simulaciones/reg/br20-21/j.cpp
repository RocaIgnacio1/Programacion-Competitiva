#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int n, k;
map<vector<int>,int> compus;

void subconjuntos(vector<int> &aux, vector<int> &nuevo, int pos, set<vector<int>> &temporal) {
    if (!nuevo.empty()) {
        temporal.insert(nuevo);
    }
    
    for(int i=pos ; i<aux.size() ; i++) {
        nuevo.push_back(aux[i]);  
        subconjuntos(aux, nuevo, i+1, temporal); 
        nuevo.pop_back(); 
    }
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   

    cin >> n >> k;
    map<int,vector<int>> cola;

    forn(i,n){
        char a;
        cin >> a;
        
        if(a == 'C'){
            int r;
            cin >> r;
            vector<int> actual;
            vector<int> vacio;
            forn(j,r){
                int v;
                cin >> v;
                actual.pb(v);
            }
            sort(actual.begin(),actual.end());
            cola[cola.size()+1] = actual;
            set<vector<int>> temporal;
            subconjuntos(actual, vacio, 0, temporal);

            for(auto i: temporal){
                compus[i]++; 
            }
        }else{
            if(a == 'D'){
                int p;
                cin >> p;
                vector<int> vacio;
                set<vector<int>> temporal;
                subconjuntos(cola[p],vacio, 0, temporal);

                for(auto i: temporal){
                    compus[i]--; 
                    if(compus.count(i)==0) compus.erase(i);
                }
                cola.erase(p);
            }else{
                int r;
                cin >> r;
                vector<int> actual;
                forn(j,r){
                    int v;
                    cin >> v;
                    actual.pb(v);
                }
                sort(actual.begin(),actual.end());
                if(compus.count(actual)>0){
                    cout << compus[actual] << endl;
                }else cout << 0 << endl;
                
            }
        }
        /*
        cout << endl << endl;
        for (auto i : compus) {
                for (auto a : i.first) {
                    cout << a << " ";
                }
                cout << " cantidad:" << i.second << endl;
            }
        */
    }

    
    return 0;
}
