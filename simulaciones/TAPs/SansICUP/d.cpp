#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)

#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    
    int n;
    cin >> n;
    int con = 0;
    forn(i, n){
        bool a = false;
        string s;
        cin >> s;
        if(s == "ch") a = true;
        if(s == "lp") a = true;
        if(s == "cbba") a = true;
        if(s == "or") a = true;
        if(s == "pt") a = true;
        if(s == "tja") a = true;
        if(s == "scz") a = true;
        if(s == "be") a = true;
        if(s == "pd") a = true;
        if(!a) con++;
    }

    cout << con;
}
