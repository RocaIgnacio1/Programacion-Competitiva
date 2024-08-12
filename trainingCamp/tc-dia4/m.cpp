#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int n;
ll h;
vector<ll> a;

bool calculo(int mid, vector<ll> &b){
    ll sum =0;
    for(int i=0; i<=mid; i++){
        if(i%2==0){
            sum+=b[i];
        }
    }
    
    if(sum>h){
        return false;
    }else return true;
}

int binarySearch(){
    int l=0,r=n-1, mid=0;
    bool ban=false;
    while(l<=r){
        mid=(l+r)/2;
        vector<ll> b=a;
        sort(b.begin(), b.begin()+mid+1,greater<ll>());
       
        if(calculo(mid,b)){
            l=mid+1;
            ban=true;
        }else{
            r=mid-1;
            ban=false;
        }
    }
    if(ban)mid++;
    return mid;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n >> h;
    forn(i,n){
        ll valor;
        cin >> valor;
        a.push_back(valor);
    }
    cout << binarySearch() << endl;
 
    return 0;
}
