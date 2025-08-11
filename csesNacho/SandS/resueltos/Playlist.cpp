#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18+100;
const ll mod = 1000000007;
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<ll> songs(n);
    forn(i,n){
        cin >> songs[i];
    }
    int ans=0, inicio=0,fin=0;
    map<ll,int> play; 
    forn(i,n){
        if(play.find(songs[i]) != play.end() && play[songs[i]]>=inicio){
            inicio=play[songs[i]]+1;  
        }
        play[songs[i]]=i;
        ans=max(ans,i-inicio+1);
    }
    cout << ans << endl;
    return 0;
}