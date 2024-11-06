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

    string s, t;
    cin >> s;
    cin >> t;

    map<char,vector<int>> apariciones;
    forn(i,s.size()){
        apariciones[s[i]].push_back(i);
    }

    int ind=0;
    int ans=1;
    forn(i,t.size()){
        char letra = t[i];
        auto it = upper_bound(apariciones[letra].begin(), apariciones[letra].end(), ind);
        if(it == apariciones[letra].end()){
            ind = apariciones[letra].front();
            ans++;
        }else{
            ind = *it;
        }
    }

    cout << ans << endl;

    /*
    cout << apariciones.size() << endl;
    for(auto i: apariciones){
        cout << i.first << endl;
        forn(j,i.second.size()){
            cout << i.second[j] << " ";
        }
        cout << endl;
    }
    */

}
