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

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    
    string t;
    cin >> t;
    int c=0;
    forn(i,t.size()){
        char l = t[i];
        if(l=='a'||l=='e'||l=='i'||l=='o'||l=='u'){
            t[i]='a';
            c++;
        }else{
            t[i]='b';
        }
    }

    if(c==0){
        cout << 1 << endl;
        return 0;
    }

    if(t[0]=='b'){
        cout << 0 << endl;
        return 0;
    }
    if(c==1){
        cout << t.size() << endl;
        return 0;
    }
    
    int countB=0, countA=0;
    string ans="";
    for(int i=t.size()-1; i>=0; i--){
        char l = t[i];
        
        if(l=='b' && countA==0)continue;
        
        if(l=='a' && countB!=0){
            break;
        }
        if(l=='b')countB++;
        if(l=='a')countA++;
        ans+=l;
    }
    
    countA=0,countB=0;
    forn(i,ans.size()){
        char l = ans[i];
        if(l=='b')countB++;
        if(l=='a')countA++;
    }

    if(countA==1 && t[t.size()-1]=='b'){

    }

    if(countA>1){
        cout << 1 << endl;
    }else{
        cout << countB << endl;
    }

    return 0;
}