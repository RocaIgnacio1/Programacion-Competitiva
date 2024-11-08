#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)

#define MAXN 500010

int res = 0;
vector<int> v, r;
void add(int i){ //modificar
    r[v[i]]++;
    if(r[v[i]] == 1) res++;
}
void remove(int i){//modificar
    r[v[i]]--;
    if(r[v[i]] == 0) res--;
}

int get_ans(){//modificar
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
