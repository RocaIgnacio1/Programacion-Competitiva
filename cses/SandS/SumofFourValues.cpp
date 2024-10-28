#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

#ifdef EBUG
//local
#else
//judge
#endif

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int n;
    ll x;
    vector<pair<ll,int>> val;
    cin >> n >> x;
    forn(i,n){
        ll p;
        cin >> p;
        val.pb(make_pair(p,i+1));
    }

    sort(val.begin(),val.end());
    if(n<4){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int a=0, b=1;
    while(true){
        forn(){
            int c=b+1, d=b+2;
            if((val[a].first + val[b].first + val[c].first + val[d].first)==x){
                cout << val[a].second << " " << val[b].second << " " << val[c].second << " " << val[d].second << endl;
                return 0;
            }else{
                if((val[a].first + val[b].first + val[c].first + val[d].first)>x){
                    break;
                }else{
                    if((val[a].first + val[b].first + val[c].first + val[d+1].first)>x){
                        c++;
                    }else{
                        d++;
                    }
                }
            }

        }
    }
    while(true){
        //cout << a << " " << b << " " << c << " " << d << endl;
        if((val[a].first + val[b].first + val[c].first + val[d].first)==x){
            cout << val[a].second << " " << val[b].second << " " << val[c].second << " " << val[d].second << endl;
            return 0;
        }else{
            if((val[a].first + val[b].first + val[c].first + val[d].first)>x){
                // se pasa
                if(c==d-1){
                    //reduzco c
                    c--;
                }else{
                    //reduzco d
                    d--;
                }
            }else{
                // le falta
                if(a==b-1){
                    //aumento b
                    b++;
                }else{
                    //reduzco a
                    a++;
                }
            }
        }
        if(b==c){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    return 0;
}