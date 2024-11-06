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
   
    int t;
    cin >> t;
    forn(w,t){
        int n;
        cin >> n;
        map<int,int> maxs;

        forn(i,n){
            int b,d;
            cin >> b >> d;
            if(maxs.count(d)==0){
                maxs[d] = b;
            }else{
                //if(i==11)cout << maxs[d] << " " << b << endl;
                if(maxs[d]<b){
                    maxs[d]=b;
                }
            }
        }

        if(maxs.size()<10){
            cout << "MOREPROBLEMS" << endl;
        }else{
            int sum=0;
            for(const auto& p:maxs){
                //cout << p.second << " ";
                sum+= p.second;
            }
            cout << sum << endl;
        }
    }
    return 0;
}