#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        deque<int> p;
        forn(i,n){
            int val;
            cin >> val;
            p.push_back(val);
        }
        
        string ans="";
        forn(i,n){
            if(i%2==0){
                if(p.front()>p.back()){
                    ans+='L';
                    p.pop_front();
                }else{
                    ans+='R';
                    p.pop_back();
                }
            }else{
                if(p.front()<p.back()){
                    ans+='L';
                    p.pop_front();
                }else{
                    ans+='R';
                    p.pop_back();
                }
            }
        }
            
        cout << ans << endl;
        
    }

    return 0;
}