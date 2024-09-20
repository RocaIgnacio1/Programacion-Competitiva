#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif
/*
derecha 1
izquierda 2
arriba 3
abajo 4
*/
ll w,h;
int borde(ll x, ll y){
    if(x == w) return 1;
    if(x == 0) return 2;
    if(y == h) return 3;
    if(y == 0) return 4;
    return 0;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> h;
    vector<pair<ll,int>> abajo;
    vector<pair<ll,int>> der;
    vector<pair<ll,int>> arriba;
    vector<pair<ll,int>> izq;
    int n;
    cin >> n;
    forn(i,n){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int b1 = borde(x1, y1);
        int b2 = borde(x2, y2);
        if(b1 != 0 && b2 != 0){
            pair<ll, int> x, y;
            if(b1 <= 2) x = make_pair(y1 ,i+1);
            else x = make_pair(x1 ,i+1);
            if(b2 <= 2) y = make_pair(y2 ,i+1);
            else y = make_pair(x2 ,i+1);
            if(b1==1) der.push_back(x);
            if(b1==2) izq.push_back(x);
            if(b1==3) arriba.push_back(x);
            if(b1==4) abajo.push_back(x);
            if(b2==1) der.push_back(y);
            if(b2==2) izq.push_back(y);
            if(b2==3) arriba.push_back(y);
            if(b2==4) abajo.push_back(y);
        }
    }
    sort(der.begin(), der.end());
    sort(izq.begin(), izq.end());
    sort(abajo.begin(), abajo.end());
    sort(arriba.begin(), arriba.end());
    reverse(arriba.begin(), arriba.end());
    reverse(izq.begin(), izq.end());
    ll sum=0;
    stack<ll> res;
    forn(i,abajo.size()){
        if(res.empty()){
            res.push(abajo[i].second);
        }else{
            if(res.top() == abajo[i].second) res.pop();
            else res.push(abajo[i].second);
        }
    }
    forn(i,der.size()){
        if(res.empty()){
            res.push(der[i].second);
        }else{
            if(res.top() == der[i].second) res.pop();
            else res.push(der[i].second);
        }
    }
    forn(i,arriba.size()){
        if(res.empty()){
            res.push(arriba[i].second);
        }else{
            if(res.top() == arriba[i].second) res.pop();
            else res.push(arriba[i].second);
        }
    }
    forn(i,izq.size()){
        if(res.empty()){
            res.push(izq[i].second);
        }else{
            if(res.top() == izq[i].second) res.pop();
            else res.push(izq[i].second);
        }
    }
    if(res.empty()){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }




    return 0;
}