#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s,t;
int dp[3000][3000];

int subsecuencia(int i, int j){

    if( i == s.size() || j == t.size() ) return 0; 

    if( dp[i][j] != -1 ) return dp[i][j];

    if ( s[i] == t[j] ) {
        dp[i][j] = 1 + subsecuencia(i+1,j+1);
        return dp[i][j];
    }
    else {
        dp[i][j] = max(subsecuencia(i+1,j), subsecuencia(i,j+1));
        return dp[i][j];
    }
}


string respuesta = "";
void sol(int i, int j){
    if(i == s.size() || j == t.size() ) return;

    if(s[i] == t[j]){
        respuesta += s[i] , sol(i+1, j+1);
    }else{
        if(dp[i+1][j] > dp[i][j+1]) sol(i+1, j);
        else sol(i, j+1);
    }
}

int main(){
    
    //freopen("input.txt", "r", stdin);
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    
    subsecuencia(0, 0);
    sol(0, 0);
    cout <<  respuesta << endl;
    
    return 0;
}
