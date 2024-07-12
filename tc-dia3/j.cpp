#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    /*freopen("input.txt", "r", stdin);*/

    ll N, K;
    ll res = 0;
    string s;
    priority_queue<ll, vector<ll>, greater<ll>> q;

    cin >> N >> K;
    vector<ll> a(N, 0);

    forn(i, N){
        cin >> a[i];
    }
    cin >> s;

    char prev = s[0];
    forn(i, N+1){
        char c = s[i];
        if (c != prev){
            while(!q.empty()){
                res += q.top();
                q.pop();
            }
        }
        q.push(a[i]);

        if (q.size() > K) {
            q.pop();
        }

        /*cout << "size: " << q.size() << endl;*/
        /*cout << c << ": " << q.top() << endl;*/

        prev = c;
    }
    cout << res << endl;
}
