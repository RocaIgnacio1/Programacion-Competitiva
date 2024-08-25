#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
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
    if (X % 2 == 0 && occurs[mid] < N - occurs[mid]){
        cout << "*" << endl;
        return 0;
    }

    sort(B.begin(), B.end());

    for(ll b : B){
        ll s = X-b;
        if (search(s) != -1){
            parejas[b] = s;
        }
    }

    for(auto i : parejas){
        if (i.first >= mid){
            break;
        }
        forn(j, occurs[i.first]){
            if (X % 2 == 0 && occurs[mid] > 0){
                cout << mid << " ";
                occurs[mid]--;
            }
            cout << i.first << " ";
        }
    }

    for(auto i : occurs){
        if (parejas.find(i.first) == parejas.end()){
            forn(j, occurs[i.first]){
                if (i.first != mid){
                    cout << i.first << " ";
                }
            }
        }
    }

    for(auto i : parejas){
        if (i.second < mid){
            break;
        }
        forn(j, occurs[i.second]){
            if (X % 2 == 0 && occurs[mid] > 0){
                cout << mid << " ";
                occurs[mid]--;
            }
            cout << i.second << " ";
        }
    }

    return 0;
}