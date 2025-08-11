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
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> separaciones;
        vector<char> ans;
        int suma=0;
        forn(i,n){
            if(i==0){
                ans.push_back(s[i]);
                suma++;
                continue;
            }

            if((s[i]=='b'||s[i]=='c'||s[i]=='d')&&(s[i-1]=='b'||s[i-1]=='c'||s[i-1]=='d')){
                ans.push_back('.');
                ans.push_back(s[i]);
            }else{
                ans.push_back(s[i]);
            }


        }
        forn(i,ans.size()){
            if(i==0){
                cout<<ans[i];
                continue;
            }
            if(i>=ans.size()-2){
                cout<<ans[i];
                continue;
            }
            if((ans[i]=='a'||ans[i]=='e') && (ans[i-1]=='b'||ans[i-1]=='c'||ans[i-1]=='d') && (ans[i+2]!='.')){
                cout<<ans[i];
                cout<<".";
            }else{
                cout<<ans[i];
            }

            
        }
        cout << endl;
    }

    return 0;
}