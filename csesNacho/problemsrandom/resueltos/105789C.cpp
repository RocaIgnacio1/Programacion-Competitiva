#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

vector<int> t;
bool check(int temp, int p){
    int j=0;
    forn(i,t.size()){
        if(t[i]<temp){
            j++;
            if(j>p)return false;
        }else{
            j=0;
        }
    }

    return true;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int p,n;
    cin >> p >> n;
    
    forn(i,n){
        int val; cin >> val;
        t.push_back(val);
    }
    vector<int> t_aux=t;
    sort(t_aux.begin(),t_aux.end());

    int l=-1, r=t_aux.size();

    while((r-l)>1){
        int mid = (r+l)/2;
        if(check(t_aux[mid],p)){
            l=mid;

        }else r=mid;
    }
    cout << t_aux[l] << endl;
    return 0;
}