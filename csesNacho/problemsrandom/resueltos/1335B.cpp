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
        int n, a, b;
        cin >> n >> a >> b;
        string abecedario = "abcdefghijklmnopqrstuvwxyz";
        vector<char> letras;
        forn(i,b){
            letras.push_back(abecedario[i]);
        }
        int j=0;
        forn(i,n){
            cout << letras[j];
            j++;
            if(j>=letras.size())j=0;
        }
        cout << endl;
    }

    return 0;
}