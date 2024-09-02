#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, g;
    map<char,int> a;
    cin >> n;
    
    vector<string> palabras;
    forn(i,n){
        string s;
        cin >> s;
        if(i==0){
            forn(j, s.size()){
                a[s[j]]++;
            }
        }
        palabras.push_back(s);
    }
    string pal=palabras[0];
   
    cin >> g;
    vector<string> val;
    forn(i,g){
        string s;
        cin >> s;
        val.push_back(s);
    }
     

    vector<string> rtas;
    forn(i,n){
        string f;
        forn(j,5){
            char letra = palabras[i][j];
            if(letra==pal[j]){
                f+='*';
            }else{
                if(a.find(letra)!=a.end()){
                    f+='!';
                }else{
                    f+='X';
                }
            }
        }
        rtas.push_back(f);
    }  

    forn(j,g){
        int ans=0;
        forn(i,rtas.size()){
            if(rtas[i].compare(val[j])==0)ans++;
        }     
        cout << ans << endl;
    }


    return 0;
}