#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define ll long long

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int t;
    cin >> t;
    forn(j,t){
        string palabra;
        cin >> palabra;
        map<char,int> c;

        forn(i,palabra.size()){
            c[palabra[i]]++;
        }

        
        if(palabra.size()==1){
            cout << "YES" << endl;
            cout << palabra[0] << endl;
            continue;
        }

        if(c.size()==1){
            cout << "NO" << endl;
            continue;
        }

        if(c.size()==2 && palabra.size()==2){
            cout << "YES" << endl;
            cout << palabra[0] << palabra[1] << endl;
            continue;
        }

        if(c.size()==2){
            bool ban=false;
            char letra;
            for(auto i:c){
                if(i.second==1){
                    letra=i.first;
                    ban=true;
                }
            }
            if(!ban){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            cout << letra;
            for(auto i:c){
                if(i.first!=letra){
                    while(i.second!=0){
                        cout << i.first;
                        i.second--;
                    }
                }
            }
            cout << endl;
            continue;
        }

        
        vector<char> res;
        cout << "YES" << endl;
        for(auto i:c){
            res.push_back(i.first);
            i.second--;
            c[i.first]--;
        }
         
       
        for(auto i:c){
            while(i.second>0){
                res.push_back(i.first);
                i.second--;
            }
        }

        forn(i,res.size()){
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}