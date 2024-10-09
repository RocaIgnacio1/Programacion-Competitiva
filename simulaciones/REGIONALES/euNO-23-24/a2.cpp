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

bool validar(deque<ll> &a, deque<ll> &b) {
    if (a.empty()) return false;
    if (b.empty()) return true;
    return a[0] < b[0];
}


ll menor(deque<ll> &a, deque<ll> &b, ll ant ){
    ll val = 1000000000000;
    if(a.empty() && b.empty()) return 0;
    if( !a.empty() && !b.empty()){
        ll fa = (a[0] + ant + 2) / 3; 
        ll fb = (b[0] + ant + 2) / 3;

        if(fa==fb)return max(a[0],b[0]);
    }
    if(!a.empty()) val = min(val, a[0]);
    if(!b.empty()) val = min(val, b[0]);
    return val;
}

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
   
    while(s>0 && (car[0].size()>0 || car[1].size()>0 || car[2].size()>0)){
        //cout << " S: " << s << endl;
        if(validar(car[0],car[1]) && validar(car[0],car[2])){
            ans++;
            s = s - (car[0][0]/3);
            car[0].pop_front();
            //cout<<endl;forn(j,3){for(auto i : car[j]){cout << i << " ";}cout << endl;}
            continue;
        }
        if(validar(car[1],car[0]) && validar(car[1],car[2])){
            
            ll ant = car[1][0];
            car[1].pop_front();
            ans++;
            ll m = menor(car[1],car[2],ant);
            if(m==0){
                s = s - ((ant/3)+1);
            }else{
                if(((ant+m)/3) <= s &&  (car[0].empty() ||  (( ant+car[0].front()+2)/3 > (m+ant+2)/3) ) ){
                    ans++;
                    //cout << "hola " << (ant+car[0].front()+2)/3 << " " <<((m+ant+2)/3)<< endl;
                    if(!car[1].empty() && m==car[1].front())car[1].pop_front();
                    else car[2].pop_front();
                    if((ant+m)%3==0)s=s-((ant+m)/3);
                    else s = s - (((ant+m)/3) + 1);
                }else s = s - ((ant/3)+1);
            }
            //cout << s << endl;
            //cout<<endl;forn(j,3){for(auto i : car[j]){cout << i << " ";}cout << endl;}
            continue;
        }
        if(validar(car[2],car[0]) && validar(car[2],car[1])){
            ll ant = car[2][0];
            car[2].pop_front();
            ans++;
            ll m = menor(car[1],car[2],ant);
            
            if(m==0){
                s = s - ((ant/3)+1);
            }else{
                
                if(((ant+m)/3) <= s &&  (car[0].empty() ||  (( m+car[0].front()+2)/3 > (m+ant+2)/3) ) ){
                    ans++;
                    if(!car[1].empty() && m==car[1].front())car[1].pop_front();
                    else car[2].pop_front();
                    if((ant+m)%3==0)s=s-((ant+m)/3);
                    else s = s - (((ant+m)/3) + 1);
                }else s = s - ((ant/3)+1);
            }
        }
        //cout<<endl;forn(j,3){for(auto i : car[j]){cout << i << " ";}cout << endl;}
    }
    cout << ans << endl;
}