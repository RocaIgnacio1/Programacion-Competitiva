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
    
    
    int C, R;
    bitset<100> s1, s2;
    vector<bitset<100>> b1;

    int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    forn(j, C){
            char p;
            cin >> p;
            tor[j][i] = (p == '1');
        }
    forn(i, R){
        forn(j, C){
            char p;
            cin >> p;
            tor[j][i] = (p == '1');
        }
    }

    return 0;
    }