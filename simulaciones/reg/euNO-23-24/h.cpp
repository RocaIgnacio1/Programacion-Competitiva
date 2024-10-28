#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    int uno = 0, dos = 0;
    forn(i, n){
        int p;
        cin >> p;
        if(p==1) uno++;
        if(p==2) dos++;
        v.push_back(p);
    }
    sort(v.begin(), v.end());

    if(uno == 0){
        cout << v[0];
        return 0;
    }

    if(uno == 1){
        cout << "(1+" << v[1] << ")";
        fora(2, i, n){
            cout << "*" << v[i];
        }
        return 0;
    }

    if(dos >= uno){
        forn(i, uno){
            if(i == uno-1) cout << "(1+2)";
            else cout << "(1+2)*";
        }
        fora(2*uno, i, n){
            cout << "*" << v[i];
        }
        return 0;
    }
    

    if(uno > dos){
        int mod = (uno-dos) % 3;
        int tres = (uno-dos)/3;
        if(uno-dos == 1){
            forn(i, dos-1){
                cout << "(1+2)*";
            }
            forn(i, tres-1){
                cout << "(1+1+1)*";
            }
            cout << "(1+1)";
            fora(uno+dos-1, i, n){
            cout << "*" << v[i];
            }
            return 0;
        }
        if(mod == 0){
            forn(i, dos){
                cout << "(1+2)*";
            }
            forn(i, tres){
                if(i!= tres-1) cout << "(1+1+1)*";
                else cout << "(1+1+1)";
            }
            fora(uno+dos, i, n){
            cout << "*" << v[i];
            }
            return 0;
        }
        if(mod == 2){
            forn(i, dos){
                cout << "(1+2)*";
            }
            forn(i, tres){
                cout << "(1+1+1)*";
            }
            cout << "(1+1)";
            fora(uno+dos, i, n){
            cout << "*" << v[i];
            }
            return 0;
        }
        
        if(mod == 1){
            forn(i, dos-1){
                cout << "(1+2)*";
            }
            forn(i, tres-1){
                cout << "(1+1+1)*";
            }
            cout << "(1+1)*(1+1)";
            fora(uno+dos-1, i, n){
            cout << "*" << v[i];
            }
            return 0;
        }
    }
    /*
    if(con == 0){
        cout << v[0];
    }
    if(con == 1){
        cout << "(1+" << v[0] << ")";
        fora(1, i, n){
            cout << "*" << v[i];
        }
    }
    if(con > 1){
        int tres = con/3;
        int mod = con%3;
        if(mod == 0){
            forn(i, tres){
                if(i!= tres-1) cout << "(1+1+1)*";
                else cout << "(1+1+1)";
            }
        }
        
        if(mod == 1){
            forn(i, tres-1){
                cout << "(1+1+1)*";
            }
            cout << "(1+1)*(1+1)";
        }
        forn(i, v.size()){
            cout << "*" << v[i];
        }
    }
    */
    
}