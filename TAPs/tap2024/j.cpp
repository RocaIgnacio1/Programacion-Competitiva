#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;

#ifdef EBUG
//local
#else
//judge
#endif

vector<ll> B;

int search(ll n){
    int l = 0, r = B.size(), mid = (l+r)/2;
    while(l <= r){
        if (n == B[mid]){
            return mid;
        }else if (n < B[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
        mid = (l+r)/2;
    }
    return -1;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int N;
    ll X; 
    map<int, int> occurs;
    map<int, int> parejas;

    cin >> N >> X;
    forn(i, N){
        ll b;
        cin >> b;
        B.push_back(b);
        occurs[b]++;
    }

    /*caso
        2 6
        3 3 3 3
    */
    if (occurs.size() == 1){
        if (B[0]+B[1] == X){
            cout << "*" << endl;
            return 0;
        }
    }

    /*caso
        4 7
        3 4 3 4
    */
    if (occurs.size() == 2){
        ll sum = 0;
        for (auto i : occurs){
            sum += i.first;
        }
        if (sum == X){
            cout << "*" << endl;
            return 0;
        }
    }

    ll mid = X/2;
    /*caso
        4 10
        4 5 5 5
    */
    auto it = occurs.find(mid);
    if (X % 2 == 0 &&  occurs.find(mid)!=occurs.end()){
        if(occurs[mid] > N-occurs[mid]+1 && occurs[mid]>1){
            cout << "*" << endl;
            return 0;
        }
    }

    sort(B.begin(), B.end());

    for(ll b : B){
        ll s = X-b;
        if (search(s) != -1){
            parejas[b] = s;
        }
    }
    vector<ll> ans;
    //meto la primera parte de las parejas
    for(auto i : parejas){
        if (i.first >= mid){
            break;
        }
        forn(j, occurs[i.first]){
            ans.pb(i.first);
        }
    }
    // separo con un mid
    if(occurs.find(mid)!=occurs.end() && parejas.size()==3){
        ans.pb(mid);
        occurs[mid]--;
    }

    // meto las no parejas
    for(auto i : occurs){
        if (parejas.find(i.first) == parejas.end()){
            forn(j, occurs[i.first]){
                if (i.first != mid){
                    ans.pb(i.first);
                }
                
            }
        }
    }

    //meto la segunda parte de las parejas
    for(auto i : parejas){
        if (i.second <= mid){
            break;
        }
        forn(j, occurs[i.second]){
            ans.pb(i.second);
        }
    }

    
    // muestro e intercalo los mid
   forn(i,ans.size()){
        if(occurs[mid]<=0){
            cout << ans[i] << " ";
            continue;
        }
        if(ans[i]!=mid && ans[i-1]!=mid){
            cout << mid << " ";
            cout << ans[i] << " ";
            occurs[mid]--;
        }else{
            cout << ans[i] << " ";
            cout << ans[i+1] << " ";
            i++;
        }
        
   }
   if(occurs[mid]>0){
        cout << mid << " ";
   }
    
    return 0;
}