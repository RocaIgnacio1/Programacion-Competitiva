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
    string s;
    cin >> s;
    int max=0, act=0, ans=0;
    forn(i,s.size()){
        if(s[i]=='+')act++;
        else act--;

        if(act>max){
            max=act;
            ans=i+1;
        }
    }

    cout << ans << endl;
    return 0;
}