#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main() {
    //freopen("input.txt","r",stdin);
    int N, M;
    map<int, int> occurs;

    cin >> N >> M;

    forn(i, N){
        int a;
        cin >> a;
        occurs[a]++;
    }
    int o =  occurs.size();
   //cout << "Cantidad: " << o << endl;
    
    // Si estan completas las ocurrencias es 0.
    if(o==M && M!=1){
        cout << 0 << endl;
        return 0;
    }

    // Si las ocurrencias son 4 o mas, se pueden representar todos los numeros
    if(o>=4 && M>4){
        cout << M << endl;
        return 0;
    }

    // Si las ocurrencias son 3.
    if(o==3){
        if(M==4 && N==3){
            cout << M-1 << endl;
            return 0;
        }else{
            cout << M << endl;
            return 0;
        }
    }
    
    // Si las ocurrencias son 2.
    if(o==2){
        if(N==2){
            cout << M-2 << endl;
            return 0;
        }
        if(N==3){
            cout << M-1 << endl;
            return 0;
        }
        bool ban=false;
        for(auto i:occurs){
            if(i.second==1)ban=true;
        }
        if(ban){
            cout << M-1 << endl;
            return 0;
        }else{
            cout << M << endl;
            return 0;
        }
    }

    // Si las ocurrencias son 1.
    if(o==1){
        cout << 1 << endl;
        return 0;
    }


    return 0;
}
