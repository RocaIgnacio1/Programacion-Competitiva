#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int a[1000][1000], n;
vector<int> movx = {1, 1, -1, -1, 2, -2, 2, -2};
vector<int> movy = {2, -2, 2, -2, 1, 1, -1, -1};
queue<tuple<int,int,int>> cola;
bool visited[1000][1000]= {false};

void bfs(int p, int z){
    cola.push({p,z,0});
    a[p][z]=0;
    int s=0;
    while(!cola.empty()){

        tuple<int,int,int> actual = cola.front();
        cola.pop();
        visited[0][0]=true;
        forn(k,8){
            int i = movx[k], j = movy[k];
            
            if((get<0>(actual)+i>=n)||(get<0>(actual)+i<0)||(get<1>(actual)+j>=n)||(get<1>(actual)+j<0))continue;

            if(!visited[get<0>(actual)+i][get<1>(actual)+j]){
                visited[get<0>(actual)+i][get<1>(actual)+j]=true;
                cola.push({get<0>(actual)+i,get<1>(actual)+j, get<2>(actual)+1});
                a[get<0>(actual)+i][get<1>(actual)+j]= get<2>(actual)+1;    
            }

        }
     
    }

}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    forn(i,n)forn(j,n)a[i][j]=0;
    bfs(0,0);
    forn(i,n){
        forn(j,n){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}