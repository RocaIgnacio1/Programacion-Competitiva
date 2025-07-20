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
    
    int n=8;
    vector<string> nombre(n);
    vector<int> fuerza(n);
    forn(i,8){
        cin >> nombre[i] >> fuerza[i];
    }
    
    int a = max(max(fuerza[0],fuerza[1]),max(fuerza[2],fuerza[3]));
    int b = max(max(fuerza[4],fuerza[5]),max(fuerza[6],fuerza[7]));

    string fin1, fin2;
    forn(i,n){
        if(fuerza[i]==a)fin1=nombre[i];
        if(fuerza[i]==b)fin2=nombre[i];
    }

    if(a>b){
        cout << fin1 << " beats " << fin2 << endl;
    }
    else cout << fin2 << " beats " << fin1 << endl;
    
    return 0;
}