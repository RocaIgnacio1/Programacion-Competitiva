#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

<<<<<<< HEAD
string u, v, uaux, vaux;
=======
>>>>>>> d64935ac35f8d730118e075953f9416c199c3bcf
#ifdef EBUG
//local
#else
//judge
#endif

string solve(string s){
    string res;
    int con = 1;
    bool ban = true;
    fora(1,i,s.size()){
        if(s[i] == s[i-1]){
            con ++;
            ban = false;
        }else{
            if(con%2 != 0){
                res.push_back(s[i-1]);
            }
            con = 1;
        }
    }
    if(con%2 != 0){
            res.push_back(s[s.size()-1]);
    }
    if(ban) return res;
    con = 1;
    return solve(res);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    forn(w, t){
        string u,v;
        cin >> u;
        cin >> v;
<<<<<<< HEAD
        int ub = 0, vb = 0;
        string uc, vc;
        forn(i, u.size()){
            if(u[i] == 'B'){
                ub++;
            }else{
                uc.push_back(u[i]);
            }
        }
        forn(i, v.size()){
            if(v[i] == 'B'){
                vb++;
            }else{
                vc.push_back(v[i]);
            }
        }
        if(ub%2 == vb%2 && solve(uc) == solve(vc)) cout << "YES" << endl;
        else cout << "NO" << endl;
=======
        
        int sumU=0;
        string aux="";
        forn(i,u.size()){
            if(u[i]=='B')sumU++;
            else aux+=u[i];
        }
        u=aux;
        aux="";
        int sumV=0;
        forn(i,v.size()){
            if(v[i]=='B')sumV++;
            else aux+=v[i];
        }
        v=aux;
        if((sumV%2==0 && sumU%2==1) || (sumV%2==1 && sumU%2==0)){
            cout << "NO" << endl;
            continue;
        }
  
            
        int ban=1;
        while(ban>0){
            ban=0;
            aux="";       
            forn(i,u.size()){
                if(i==u.size()-1)aux+=u[i];
                else{
                    if((u[i]=='A' && u[i+1]=='A') || (u[i]=='C' && u[i+1]=='C')){
                        //cout << u[i] << " " << u[i+1] << endl;
                        i++;
                        ban++;
                    }else aux+=u[i];
                }
                
            }
            u=aux;
        }
        aux="";
        ban=1;
        while(ban>0){
            ban=0;
            aux="";
            forn(i,v.size()){
                if(i==v.size()-1)aux+=v[i];
                else{
                    if((v[i]=='A' && v[i+1]=='A') || (v[i]=='C' && v[i+1]=='C')){
                        i++;
                        ban++;
                    }else aux+=v[i];
                }
                
            }
            v=aux;
        }
        
        
        if(u.compare(v)==0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
>>>>>>> d64935ac35f8d730118e075953f9416c199c3bcf
    }

}