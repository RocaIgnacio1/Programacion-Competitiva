#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
#else
#endif

#define MAXN 500010

int res = 0;
vector<int> v, r;
void add(int i){
    r[v[i]]++;
    if(r[v[i]] == 1) res++;
}
void remove(int i){
    r[v[i]]--;
    if(r[v[i]] == 0) res--;
}

int get_ans(){
    return res;
}
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;}; // O((n+nq)*sqrt(n)*update)
qu qs[MAXN];
int ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
    forn(i,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    forn(i,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int, int> aux;
    cin >> n >> nq;
    int con = 0;
    forn(i, n){
        int p;
        cin >> p;
        if(aux.count(p)==0){
            aux[p]=con;
            r.push_back(0);
            v.push_back(con);
            con++;
        }else{
            v.push_back(aux[p]);
        }
    }
    forn(i, nq){
        int x, y;
        cin >> x >> y;
        qs[i] = {x-1, y, i};
    }
    mos();
    forn(i, nq){
        cout << ans[i] << '\n';
    }
    return 0;
}