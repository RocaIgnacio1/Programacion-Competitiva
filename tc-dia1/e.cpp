#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> A;

    forn(i, n){
        int a;
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    ll sum = 0, total;
    for(int a: A){
        sum += a;
    }
    total = sum;

    for(int a: A){
        total -= a;
        sum += total + a;
    }
    sum -= A[A.size()-1];
    cout << sum << endl;

    return 0;
}
