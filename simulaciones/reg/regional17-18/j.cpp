#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    
    string s;
    cin >> s;
    int len = s.size();

    int rocas=0, pozos=0;
    forn(i,len){
        if(s[i]=='R')rocas++;
        else pozos++;  
    }
    if(rocas==len){
        cout << len-1 << endl;
        return 0;
    }
    if(pozos==len){
        cout << 0 << endl;
        return 0;
    }

    vector<int> divs;

    for(int i=2; i<len; i++){
        if(len%i==0){
            divs.pb(i);
        }
    }
    /*
    forn(i,divs.size()){
        cout << divs[i] << " ";
    }
    cout << endl;
    */
    vector<int> ans;
    bool ban=false;
    forn(i,divs.size()){
        
        ban=false;
        forn(j,divs[i]){
            int vuelta=0, cont=j;
            if(ban)break;
            while(vuelta<2){
                if(cont==j){
                    vuelta++;
                    if(vuelta==2){
                        ban=true;
                        ans.pb(divs[i]);    
                    }
                }
                if(s[cont]=='P')break;    
                cont = (cont+divs[i])%len;
            }
        }
        
    }
    set<int> mult;
    forn(i, ans.size()){
        mult.insert(ans[i]);
    }
    forn(j,ans.size()){
        for (int i=2; (i*ans[j])<len;i++) {
            mult.insert(i*ans[j]);
        }
    }
    /*
    for(int x: mult){
        cout << x << " "; 
    }
    cout << endl;
    */

    cout << mult.size() << endl;
    
    return 0;
}