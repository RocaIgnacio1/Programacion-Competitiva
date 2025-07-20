//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)
using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int t;
    cin >> t;
    forn(j,t){
        int n;
        string a;
        cin >> n;
        cin >> a;
        vector<int> nums(n);
        forn(i,n)cin >> nums[i];
        if(n==2){
            cout << "Alice" << endl;
            continue;
        }
        int num;
        
        if(n==3){
           num = 100*nums[0]+10*nums[1]+nums[2];

           if(a=="Alice"){
                if(num==132){
                    cout << "Alice" << endl;
                    continue;
                }
                if(num==213){
                    cout << "Alice" << endl;
                    continue;
                }
                if(num==321){
                    cout << "Alice" << endl;
                    continue;
                }
                if(num==123){
                    cout << "Bob" << endl;
                    continue;
                }
                if(num==231){
                    cout << "Bob" << endl;
                    continue;
                }
                if(num==312){
                    cout << "Bob" << endl;
                    continue;
                }
           }else{
                if(num==132){
                    cout << "Bob" << endl;
                    continue;
                }
                if(num==213){
                    cout << "Bob" << endl;
                    continue;
                }
                if(num==321){
                    cout << "Bob" << endl;
                    continue;
                }
                if(num==123){
                    cout << "Alice" << endl;
                    continue;
                }
                if(num==231){
                    cout << "Alice" << endl;
                    continue;
                }
                if(num==312){
                    cout << "Alice" << endl;
                    continue;
                }
           }
        }
           
           int malparados=0;
           forn(i,n){
                if((i+1) != nums[i])malparados++;
           }

           if(a=="Alice" && malparados==2){
                cout << "Alice" << endl;
                continue;
           }
           if(a=="Bob" && malparados==0){
                cout << "Alice" << endl;
                continue;
           }

           cout << "Bob" << endl;
            
        
        

        
    }
    return 0;
}