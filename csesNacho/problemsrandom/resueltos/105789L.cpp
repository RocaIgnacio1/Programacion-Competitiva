#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forr(i, p, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define MAXN 200000

vector<string> num;


int check(string s, int numero){
    int ans=numero, j=0;
    for(auto i: num[numero]){
        if(s[j]=='+'||s[j]=='-'){
            j++;
            continue;
        }   
        if(s[j]!=i)ans=-1;
        j++;
    }
    return ans;
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> a(n);
    forn(i,n){
        cin >> a[i];
    }

    num.push_back("GGGgGGG");
    num.push_back("gggggGG");
    num.push_back("gGGGGGg");
    num.push_back("ggGGGGG");
    num.push_back("GggGgGG");
    num.push_back("GgGGGgG");
    num.push_back("GGGGGgG");
    num.push_back("ggGggGG");
    num.push_back("GGGGGGG");
    num.push_back("GgGGGGG");
    string ans="";
    forn(i,n){
        int suma=0, solve, rta;
        forn(j,10){
            solve = check(a[i],j);
            if(solve!=(-1)){
                suma++;
                rta = solve;
            }
        }
        if(suma>1)ans+="*";
        else ans+= to_string(rta);
    }
    cout << ans << endl;
    return 0;
}