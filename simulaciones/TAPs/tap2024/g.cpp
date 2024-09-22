#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)

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
    map<char,int> a;
    forn(i,s.size()){
        //cout << s[i] << endl;
        a[s[i]]++;
    }
    int ans=0;
    //cout << a['P'] << endl;
    ans = min(a['P'], a['U']+a['A']);
    ans = min(ans, a['T']);

    cout << ans << endl;

    return 0;
}