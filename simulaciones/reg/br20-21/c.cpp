#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int n;
vector<int> v;
ll tot = 0;

ll solve(){
    forn(i, n){
        v[i]-=tot;
    }
    ll min = 1;
    ll ac = 0;
    
    int I = 0;
    forn(i, 3*n){
        ac += v[i%n];
        if(ac < min){
            min = ac;
            I = (i+1)%n;
        }
    }
    //cout << I << endl;
    ll acum = 0, acum2 = 0;
    int  con = 0;
    set<int> s;
    while(con != n){
        if(v[I%n] > 0){
            acum+=v[I%n];
            v[I%n] = 0;
            s.insert(I%n);
            con++;
        }else{
            if(v[I%n] < 0){
                if(acum >= -v[I%n]){
                    acum += v[I%n];
                    v[I%n] = 0;
                }else{
                    v[I%n] += acum;
                    acum = 0;
                }
            }
        }
        if(s.count(I%n) == 0){
            if(v[I%n] == 0){
                s.insert(I%n);
                con++;
            }
        }
        //for(auto i: v){
          //  cout << i << " ";
        //}cout << endl;
        //cout << acum << " "<< I%n << endl;
        acum2 += acum;
        I++;
    }
    return acum2;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> aux;
    cin >> n;
    forn(i, n){
        int p;
        cin >> p;
        tot+=p;
        v.push_back(p);
        aux.push_back(p);
    }
    tot/=n;
    ll mini = solve();
    v = aux;
    reverse(v.begin(), v.end());
    mini = min(mini, solve());
    cout << mini << endl;
    
    
    return 0;
}