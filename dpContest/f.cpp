#include <bits/stdc++.h>
using namespace std;

string dp[3000][3000];

string subsecuencia(string s, string t, int i, int j){

    if( dp[i][j] != "" ) return dp[i][j];
    if( s[i] == '\0' || t[j] == '\0' ) return ""; 

    if ( s[i] == t[j] ) {
        dp[i][j] = s[i] + subsecuencia(s,t,i+1,j+1);
        return dp[i][j];
    }
    else {
        string a = subsecuencia(s,t,i+1,j);
        string b = subsecuencia(s,t,i,j+1);
        if( a.size() > b.size() ) dp[i][j] = a;
        else dp[i][j] = b;
        return dp[i][j];
    }
}

int main(){

    string s,t;
    freopen("input.txt", "r", stdin);
    cin >> s >> t;
    for(int i=0; i<3000; i++)
        for(int j=0; j<3000; j++)
            dp[i][j] = "";

    cout << subsecuencia(s, t, 0, 0) << endl;


    return 0;
}