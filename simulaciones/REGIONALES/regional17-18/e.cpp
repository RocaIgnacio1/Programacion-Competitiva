#include <bits/stdc++.h>
using namespace std;
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


string s;
int n, dp[1001][1001], build[1001];
bool sol(int pos, int res){
    if(pos==s.size())return res==0;
    if(dp[pos][res]!=-1)return dp[pos][res];

    if(s[pos]!='?'){
        int dig = s[pos] - '0';
        return dp[pos][res] = sol(pos+1,((res*10)+dig)%n);
    }else{
        forn(i,10){
            if(pos==0&&i==0)continue;
            if(sol(pos+1,((res*10)+i)%n)){
                build[pos]=i;
                return dp[pos][res] = true;
            }
        }
    }

    return dp[pos][res] = false;   
}



int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    
    cin >> s >> n;
    memset(dp, -1, sizeof(dp));
    if(sol(0,0)){
        forn(i,s.size()){
            if(s[i]!='?'){
                cout << s[i];
            }else{
                cout << build[i];
            }
        }
    }else{
        cout << "*" << endl;
    }

    return 0;
}