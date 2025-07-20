#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define ll long long

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    forn(j, t){
        int n;
        cin >> n;
        vector<vector<int>> v;
        vector<int> ret(n+1);
        vector<int> aux;
        set<int> s;
        aux.push_back(1);
        v.push_back(aux);
        s.insert(0);
        int lastnum = 1;
        forn(i, n){
            cout << "? " << 1 << " " << i+2 << endl;
            cout.flush();
            bool res;
            cin >> res;
            if(res){
                vector<int> aux;
                aux.push_back(i+2);
                v.push_back(aux);
                s.insert(i+1);
            }else{
                v[0].push_back(i+2);
                lastnum = i+3;
                break;
            }
        }
        set<int> sa;
        bool ban = true;
        forn(i, n+1){
            if(ban){
                sa = s;
                for(auto it: sa){
                    cout << "? " << lastnum << " " << v[it][v[it].size()-1] << endl;
                    cout.flush();
                    bool res;
                    cin >> res;
                    if(!res){
                        v[it].push_back(lastnum);
                        lastnum++;
                    }else{
                        if( v[it].size() <= i+1){
                            s.erase(it);
                        }
                    }
                    if(lastnum == n+1){
                        ban = false;
                        break;
                    } 
                }
            }
        }
        
        forn(i, v.size()){
            forn(j, v[i].size()){
                if(j == 0){
                    ret[v[i][j]] = 0;
                }else{
                    ret[v[i][j]] = v[i][j-1];
                }
            }
        }
        cout << "! ";
        forn(i, ret.size()){
            if(i == 0) continue;
            cout << ret[i] << " ";
        }
        cout << endl;
        cout.flush();
    } 
    return 0;
}