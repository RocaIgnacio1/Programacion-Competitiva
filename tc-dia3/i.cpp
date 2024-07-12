#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define F0 "What are you doing at the end of the world? Are you busy? Will you save us?"
#define Y1 "What are you doing while sending "
#define Y2 "Are you busy? Will you send "
#define Y3 "?"

#define f0 sizeof(F0) - 1
#define y1 sizeof(Y1) - 1
#define y2 sizeof(Y2) - 1
#define y3 sizeof(Y3) - 1

char find(int n, ll k){
    if (k < y1){
        return Y1[k];
    }

    return '-';
}

int main(){
    freopen("input.txt", "r", stdin);
    cout << f0 << " " << y1 << " " << y2 << " " << y3 << endl;

    int q;
    cin >> q;
    
    forn(i, q){
        int n;
        ll k;
        cin >> n >> k;
        cout << find(n, k-1) << endl;
    }

    return 0;
}
