#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif
    int k;
    string s;
    cin >> s;
    cin >> k;

    vector<string> a(k);
    forn(i,s.size()){
        a[i%k]+=s[i];
    }
    
    forn(i,k){
        sort(a[i].begin(),a[i].end());
    }
    

    int ind=0;
    forn(i,s.size()){
        if(i!=0 && i%k==0)ind++;
        cout << a[i%k][ind];
    }
    
    return 0;
}