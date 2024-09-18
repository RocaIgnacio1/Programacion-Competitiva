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
    int l = 0, r = B.size() - 1; 
    while(l <= r){
        int mid = (l + r) / 2;
        if (n == B[mid]){
            return mid;
        } else if (n < B[mid]){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int main(){
    #ifdef EBUG
        freopen("in1.txt", "r", stdin);
    #endif
    int N;
    ll X; 
    map<ll, int> occurs;
    map<ll, int> parejas;

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
    
    // parejas parte izquierda
    for(auto i : parejas){
        if (i.first >= i.second)break;
        forn(j, occurs[i.first]){
            if(X%2==0 && occurs.find(mid)!=occurs.end() && occurs[mid]>1){
                occurs[mid]--;
                ans.push_back(mid);
            }
            ans.push_back(i.first);
        }    
    }

    // mid separador
    if(X%2==0 && occurs.find(mid)!=occurs.end() && occurs[mid]>0){
        occurs[mid]--;
        ans.push_back(mid);
    }

    // no parejas
    for(auto i : occurs){
        if (parejas.find(i.first) == parejas.end()){
            forn(j, occurs[i.first]){
                ans.push_back(i.first);
                if(X%2==0 && occurs.find(mid)!=occurs.end() && occurs[mid]>0){
                    occurs[mid]--;
                    ans.push_back(mid);
                }
            }
        }
    }

    // parejas der a la derecha
    for(auto i : parejas){
        if (i.second <= i.first)break;
        forn(j, occurs[i.second]){
            ans.push_back(i.second);
            if(X%2==0 && occurs.find(mid)!=occurs.end() && occurs[mid]>0){
                occurs[mid]--;
                ans.push_back(mid);
            }
        }
    }
    

    forn(i,ans.size()){
        cout << ans[i] << " ";
    }


    return 0;
}