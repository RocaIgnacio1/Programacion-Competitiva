#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll s;
    cin >> n >> s;
    deque<ll> c;
    forn(i,n){
        ll a;
        cin >> a;
        c.push_back(a);
    }
    sort(c.begin(),c.end());
    c.pop_back();
    
    int ans=0;
    s--;
    ans++;
    map<int,deque<ll>> car;
    forn(i,n-1){
        if(c[i]%3==0){
            car[0].push_back(c[i]);
        }
        if(c[i]%3==1){
            car[1].push_back(c[i]);
        }
        if(c[i]%3==2){
            car[2].push_back(c[i]);            
        }
    }
    /*
    if(car[1][0]<car[0][0] && car[1][0]<car[2][0]){
        cout << "hola" << endl;
    }
    */
    /*
    forn(i,3){
        for(auto i : car[i]){
            cout << i << " ";
        }
        cout << endl;
    }
    */
    while(s>0 && (car[0].size()>0 || car[1].size()>0 || car[2].size()>0)){
        cout << s << endl;
        if(car[0][0]<car[1][0] && car[0][0]<car[2][0]){
            
            ans++;
            s = s - (car[0][0]/3);
            car[0].pop_front();
            continue;
        }
        if(car[1][0]<car[0][0] && car[1][0]<car[2][0]){
            
            ll ant = car[1][0];
            car[1].pop_front();
            ans++;
            if(car[2].size()!=0){
                if(ant+car[2][0] < ant+car[1][0]){
                    s = s - ((ant+car[2][0])/3);
                    car[2].pop_front();
                    ans++;
                }else s = s - ((ant/3)+1);
            }else s = s - ((ant/3)+1);

            //cout << "entro" << endl;
        }
        if(car[2][0]<car[0][0] && car[2][0]<car[1][0]){
            ll ant = car[1][0];
            car[2].pop_front();
            ans++;
            if(car[1].size()!=0){
                if(ant+car[1][0] < ant+car[2][0]){
                    s = s - ((ant+car[1][0])/3);
                    car[1].pop_front();
                    ans++;
                }else s = s - ((ant/3)+1);
            }else s = s - ((ant/3)+1);
        }
        /*
        forn(i,3){
            for(auto i : car[i]){
                cout << i << " ";
            }
            cout << endl;
        }
        */
        
    }
    
    cout << ans << endl;
    
}