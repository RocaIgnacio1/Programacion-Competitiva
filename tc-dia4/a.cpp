#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

vector<ll> A;

int search(int n){
    int l = 0;
    int r = A.size() - 1; 
    int mid = (l+r)/2;

    while(l <= r){
        if (A[mid] == n)
            return mid;

        if (A[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main(){
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    cout << t << endl;

    forn(i, t){
        int n;
        cin >> n;
        //A.clear();

        forn(j, n){
            ll a;
            cin >> a;
            cout << a << " ";
            A.push_back(a);
        }
        cout << "a";

        sort(A.begin(), A.end());
       
        forn(j, n){
            ll num = j;
            while(num <= n){
                int pos = search(num);
                if (pos == -1){
                    cout << "NO" << endl;
                }
                num *= 2;
            }
        }
        cout << "YES" << endl;
    }
}
