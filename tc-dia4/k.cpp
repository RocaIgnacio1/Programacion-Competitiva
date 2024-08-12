#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum=0;
    forn(i,s.size()){
        if(s[i]=='-' && sum>0)sum--;
        if(s[i]=='+')sum++;
    }
    if(sum<0)sum=0;
    cout << sum << endl;
}