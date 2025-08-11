#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        //freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    vector<int> ans;
    for(int i=2; i<=n; i=i+2){
        ans.push_back(i);
    }
    for(int i=1; i<=n; i=i+2){
        ans.push_back(i);
    }
    forn(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}

//2 4 1 3