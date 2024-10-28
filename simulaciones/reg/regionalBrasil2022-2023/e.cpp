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

int n;
int dp[1001];
int disp[1001];
int solve(int i, int D){
    cout << disp[i] << " ";
    if (dp[i] != -1) return dp[i];
    if (D <= 0) return 0;
    if (i >= n-1) return dp[i];

    return dp[i] = max(solve(i+1, D), disp[i+1] + solve(i+1, D-disp[i+1]));
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,e, ans=0;
    cin >> n >> k >> e;
    int x=0,y=0,z=0;
    y=e;
    x=k;
    z= n-(e+k);
    int usados[n+1];
    forn(i,n+1){
        if(i==k)usados[i]=1;
        else{
            usados[i]=0;
        }
    }
    if(x==y && x!=0){
        bool ban=false;
        forn(i,y){
            if(usados[i]==0 && usados[y-i]==0 && i!=(y-i)){
                //cout << i << " " << y-i << endl;
                usados[i]=1;
                usados[y-i]=1;
                ban=true;
                break;
            }
        }
        if(!ban){
            ans+=1;
            usados[y-1]=1;
        }
    }else{
        usados[y]=1;
    }
    bool ban=false;
        usados[0]=0;
        forn(i,z){
            if(usados[i]==0 && usados[z-i]==0 && i!=(z-i)){
                usados[i]=1;
                usados[z-i]=1;
                ban=true;
                break;
            }
        }
        if(!ban){
            int sum=0;
            
            forn(i, n){
                if(usados[i]==1){
                    disp[i] = i;
                }
            }
            memset(dp, -1, sizeof(dp));
            cout << solve(0, z) << endl;
        }

    cout << ans << endl;
    return 0;
}