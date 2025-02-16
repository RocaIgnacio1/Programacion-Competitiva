#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)

typedef long long ll;

int main(){
    ll N, S, K;
    vector<int> A;
    cin >> S >> N >> K;
    ll ans = N/S;

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    for (auto i = A.begin(); i != A.end();) {
        bool borrado = false;
        for (auto j = i+1; j != A.end(); ++j) {
            /*cout << *i << "%" << *j << endl;*/
            if (*i % *j == 0) {
                /*cout << "borrar " << *i << endl;*/
                i = A.erase(i);
                borrado = true;
                break;
            }
        }
        if (!borrado) {
            ++i;
        }
    }
    /*for (auto a : A) {*/
    /*    cout << a << " ";*/
    /*}*/
    /*cout << endl;*/

    for (auto a : A) {
        ll m = lcm(S, a);
        /*cout << S << " " << m << "=" << m << endl;*/
        ans -= N/m;
        if (ans == 0) {
            break;
        }
    }

    cout << ans << endl;
}
