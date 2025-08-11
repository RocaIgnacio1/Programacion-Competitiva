#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
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

bool ask(int i, int j){
    string res;
    cout << "? " << i << " " << j << endl;
    cout.flush();
    cin >> res;
    return res=="YES";
}

int main() {
    #ifdef EBUG
        //freopen("in1.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector<int> ans(n+1);
    forn(i,n){
           
        int a=1, b=n, mid=(a+b)/2, res=-1;
        while(a<=b){
            if(ask(i+1,mid)){
                res=mid;
                b=mid-1;
            }else{
                a=mid+1;
            }
            mid=(a+b)/2;
        }
        ans[res]=mid;
        
    }
    cout << "! ";
    forn(i,ans.size()){
        if(i==0)continue;
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}