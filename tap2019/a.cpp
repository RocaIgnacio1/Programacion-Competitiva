#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt","r",stdin);
    string s;
    cin >> s;

    char letra = s[s.size()-1];
    //cout << s[s.size()-1] << endl;
    
    if(letra=='a'){
        s[s.size()-1]='i';
        s += 'c';
        s += 'a';
    }else{
        s[s.size()-1]='i';
        s += 'c';
        s += 'o';
    }

    cout << s << endl;
}