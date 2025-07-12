/** 
 * Given a string and a pattern, your task is to count the number of positions
 * where the pattern occurs in the string.
 *
Input:
saippuakauppias
pp

Output:
2
**/

#include <bits/stdc++.h>
#include "hashing.h"
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)

using namespace std;

#define pb push_back
typedef long long ll;
#define MAXN 1000000010

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s,t;
    cin >> s >> t;
    Hash h(s);
    Hash ha(t);
    int n = s.size(), res=0;

    forn(i, n-t.size()+1){
        if(t.size() > s.size()) break;
        if(h.get(i,i+t.size()-1) == ha.get(0,t.size()-1)) res++;
    }

    cout << res << endl;
    return 0;
}
