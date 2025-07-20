//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;

using namespace std;
typedef pair<int, int> ii;

const int MAXN = 1e5+10;




#define INF 1e9
int N;
#define MAX_V 250001
vector<ii> G[MAX_V];
//To add an edge use
#define add(a, b, w) G[a].pb(make_pair(w, b))
vector<int> ways2;
vector<ll> fin, inicio;

vector<ll> dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	vector<ll> dist(N, INF); vector<int> dad(N, -1);
	Q.push(make_pair(0, s)); dist[s] = 0;
    vector<int> ways(N, 0);
    ways[s] = 1;
	while(sz(Q)){
        ii p = Q.top(); Q.pop();
		if(p.snd == t) break;
		forall(it, G[p.snd])
        if(dist[p.snd]+it->first < dist[it->snd]){
            dist[it->snd] = dist[p.snd] + it->fst;
            dad[it->snd] = p.snd;
            ways[it->snd] = 1;
            Q.push(make_pair(dist[it->snd], it->snd));	}
            else{
                if (dist[p.snd]+it->first == dist[it->snd]) {
                    ways[it->snd] += 1;
                }
            }
        }
        ways2 = ways;
        return dist;
        if(dist[t]<INF)//path generator
        for(int i=t; i!=-1; i=dad[i])
        printf("%d%c", i, (i==s?'\n':' '));
    }

    vector<int> cams;
    void bfs(int i){
        queue<int> q;
        q.push(i);
        vector<bool> visitado(N, false);
        visitado[i] = true;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto y: G[x]){
                auto a = y.second;
                if(min(fin[a] + inicio[x], fin[x] + inicio[a]) + y.first == fin[i]){
                    cout << x << " " << a << endl;
                    cams[a]++;
                    cams[x]++;
                }
                if(!visitado[a]){
                    q.push(a);
                    visitado[a] = true;
                }
            }
    
        }
    }

    int main() {
        #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif
    int m, s, t;
    cin >> N >> m >> s >> t; s--; t--;
    vector<array<int, 3>> v;
    forn(i, m){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        add(a,b,w);
        add(b,a,w);
        v.push_back({a, b, w});
    }
    
    inicio = dijkstra(s,t), fin = dijkstra(t, s);
    forn(i, N){
        cams.push_back(0);
    }
    bfs(s);
    forn(i, N){
        cout << cams[i] <<  " " << inicio[i] << " " << fin[i] << endl;
    }
    forn(i, m){
        auto a = v[i][0];
        auto b = v[i][1];
        auto w = v[i][2];
        //cout << fin[a] << " " << fin[b] << " " << inicio[a] << " " << inicio[b] << endl;
        ll minimo = min(fin[a] + inicio[b], fin[b] + inicio[a]);
        //cout << minimo << " " << fin[s] << endl;
        ll tam = minimo + w - fin[s];
        if(tam == 0){
            if(cams[a] == 1 || cams[b] == 1){
                cout << "YES" << endl;
            }else{
                cout << "CAN 1" << endl;
            }
        }else{
            if(tam < 0){
                cout << "NO" << endl;
            }else{
                cout << "CAN " << tam + 1  << endl;
            }
        }
    }

    return 0;
}
