#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

typedef unsigned long long ll;

const int BITS = 30;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> A(n);

        forn(i, n){
            cin >> A[i];
        }

        vector<int> count(BITS, 0);
        forn(i, n){
            forn(b, BITS){
                if (A[i] & (1 << b)) {
                    count[b] += 1;
                }
            }
        }

        ll ans = 0;
        forn(i, n){
            ll sum = 0;
            forn(b, BITS){
                if (A[i] & (1 << b)) { // bit = 1
                    sum += (n - count[b]) * (1LL << b);
                } else { // bit = 0
                    sum += count[b] * (1LL << b);
                }
            }
            ans = max(ans, sum);
        }

        /*ll ans = 0;*/
        /*forn(i, n){*/
        /*    ans += A[i] ^ A[k];*/
        /*}*/
        cout << ans << '\n';
    }

    return 0;
}
