#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back
typedef long long ll;
#ifdef EBUG
//local
#else
//judge
#endif

const int MAXN = 1e5 + 1;

int n, m, A, B;
vector<int> adj[MAXN];
int gr[MAXN];
set<pair<int, int>> s;

int main(){
    #ifdef EBUG
        freopen("b.in1", "r", stdin);
    #endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> A >> B;
    forn(i, m){
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    forn(i, n){
        gr[i] = adj[i].size();
        s.insert({gr[i], i});
    }
    /*forn(i, n){
        cout << i+1 << ": " << gr[i] << endl;
    }*/

    while(s.size() > 0){
        int i;
        int min = s.begin()->second;
        int max = s.rbegin()->second;
        //cout << min << ' ' << max << endl;

        if(n - 1 - gr[max] < B){
            i = max;
        }else if(gr[min] < A){
            i = min;
        }else{
            break;
        }
        //cout << i+1 << endl;
        s.erase({gr[i], i});

        for(auto u : adj[i]){
            if (s.find({gr[u], u}) != s.end()){
                s.erase({gr[u], u});
                gr[u]--;
                s.insert({gr[u], u});
            }
        }
        n--;
    }
    cout << s.size() << '\n';
    
    return 0;
}
