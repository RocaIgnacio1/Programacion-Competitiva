#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

typedef long long ll;

int n;

bool solve(int a, vector<ll> &S, map<ll, int> apps){
    vector<ll> r(n);
    r[n-1] = a;
    for (int i = n-2; i >= 0; i--){
        r[i] = S[i+1] - r[i+1];
        //cout << r[i] << ' ';
        if (apps.find(r[i]) != apps.end()) apps[r[i]]--;
        if (apps[r[i]] <= 0) return false;
    }
    forn(i, n){
        cout << r[i] << ' ';
    }
    cout << '\n';
    return true;
}

bool solve2(int a, vector<ll> &S, map<ll, int> apps){
    vector<ll> r(n);
    r[0] = a;
    for (int i = 0; i < n-1; i++){
        r[i+1] = S[i] - r[i];
        //cout << r[i] << ' ';
        if (apps.find(r[i+1]) != apps.end()) apps[r[i+1]]--;
        if (apps[r[i+1]] <= 0) return false;
    }
    forn(i, n){
        cout << r[i-1] << ' ';
    }
    cout << '\n';
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<ll> S(n+1); S[0] = 0;
    vector<ll> R(n);
    vector<ll> X(n);
    map<ll, int> apps;

    forn(i, n){
        cin >> X[i];
    }

    forn(i, n){
        S[i+1] = X[i+1] - X[i];
        cin >> R[i];
        apps[R[i]]++;
    }
    sort(R.begin(), R.end());

    /*forn(i, n){*/
    /*    cout << S[i] << ' ';*/
    /*}*/
    /*cout << '\n';*/

    int l = 0, r = R.size() - 1, mid = (l+r)/2;
    while(l <= r){
        mid = (l+r)/2;
        /*cout << S[n-1];*/
        /*cout << -R[mid] << ": " << endl;*/

        forn(i, n){
            apps[R[i]]++;
        }
        if(solve(S[n-1] - R[mid], S, apps)){
            r = mid-1;
            return 0;
        }else{
            /*cout << "false" << endl;*/
            l = mid+1;
        }
    }

    l = 0, r = R.size() - 1, mid = (l+r)/2;
    while(l <= r){
        mid = (l+r)/2;
        /*cout << S[n-1];*/
        /*cout << -R[mid] << ": " << endl;*/

        forn(i, n){
            apps[R[i]]++;
        }
        if(solve2(S[n-1] - R[mid], S, apps)){
            r = mid-1;
            return 0;
        }else{
            /*cout << "false" << endl;*/
            l = mid+1;
        }
    }

    return 0;
}
