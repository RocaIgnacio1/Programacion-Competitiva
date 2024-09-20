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

struct resp{
    ll first, second,third;
};

int n;
ll x;
vector<ll> a;

ll search(int j, ll num){
    int l=j, r=n-1, mid=0;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid]==num){
            return num;
        }

        if(a[mid]>num){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return -1;
}

int main() {
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    cin >> n >> x;
    forn(i,n){
        ll num;
        cin >> num;
        a.pb(num);
    }
    vector<ll> b=a;
    sort(a.begin(),a.end());
    
    resp ans;
    bool ban=false;
    forn(i,n-2){
        for(int j=i+1; j<n-1; j++){
            ll buscar = search(j+1, x-(a[i]+a[j]));
            if(buscar!=-1){
                ans.first = a[i];
                ans.second = a[j];
                ans.third = buscar;
                ban=true;
            }
        }
    }
    
    if(!ban)cout << "IMPOSSIBLE";
    else{
        forn(i,n){
            if(b[i]==ans.first){
                ans.first=-1;
                cout << i+1 << " ";
            }else{
                if(b[i]==ans.second){
                    ans.second=-1;
                    cout << i+1 << " ";
                }else{
                        if(b[i]==ans.third){
                        ans.third=-1;
                        cout << i+1 << " ";
                    }
                }
            }
            
            
        }
    }
    cout << endl;

    return 0;
}