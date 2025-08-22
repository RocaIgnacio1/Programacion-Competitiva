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
    freopen("l.txt", "r", stdin);
    #endif

    int t=1;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> a(m);
        forn(i,m)cin >> a[i];
        
        if(n==2){
            cout << "N" << endl;
            return 0;
        }
        bool ans=true, baja=false;
        int anterior=0;
        forn(i,m-1){
            if((a[i]==1 && a[i+1]==2) || (a[i]==2 && a[i+1]==1)){
                ans=false;
                break;
            }
            if(abs(a[i]-a[i+1])!=1 && abs(a[i]-a[i+1])!=2){
                ans=false;
                break;
            }
            if(anterior==a[i]-a[i+1]){
                ans=false;
                break;
            }
            
            if(baja && a[i]<a[i+1]){
                ans=false;
                break;
            }
            
            if(a[i]>a[i+1]){
                baja=true;
            }
            anterior = a[i+1]-a[i];
        }

        if(ans)cout << "S" << endl;
        else cout << "N" << endl;
        
    }

    
    return 0;
}