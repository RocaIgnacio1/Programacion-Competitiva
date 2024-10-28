#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int xs, xp, xt, ys, yp, yt;
    cin >> xs >> ys;
    cin >> xt >> yt;
    cin >> xp >> yp;
    if(xp > xs && xp > xt){
        if(yp > ys && yp > yt){
            cout << 1 << endl;
            cout << xt << " " << ys << endl;
            return 0;
        }
        if(yp < ys && yp < yt){
            cout << 1 << endl;
            cout << xt << " " << ys << endl;
            return 0;
        }
        cout << 2 << endl;
        cout << -1000000 << " " << ys << endl;
        cout << -1000000 << " " << yt << endl;
        return 0;
    }
    if(xp < xs && xp < xt){
        if(yp < ys && yp < yt){
            cout << 1 << endl;
            cout << xt << " " << ys << endl;
            return 0;
        }
        if(yp > ys && yp > yt){ 
            cout << 1 << endl;
            cout << xt << " " << ys << endl;
            return 0;
        }
        cout << 2 << endl;
        cout << 1000000 << " " << ys << endl;
        cout << 1000000 << " " << yt << endl;
        return 0;
    }

    if(yp > ys && yp > yt){
        cout << 2 << endl;
        cout << xs << " " << -1000000 << endl;
        cout << xt << " " << -1000000 << endl;
        return 0;
    }
    if(yp < ys && yp < yt){
        cout << 2 << endl;
        cout << xs << " " << 1000000 << endl;
        cout << xt << " " << 1000000 << endl;
        return 0;
    }
    cout << 4 << endl;
    cout << -1000000 << " " << ys << endl;
    cout << -1000000 << " " << 1000000 << endl;
    cout << 1000000 << " " << 1000000 << endl;
    cout << 1000000 << " " << yt << endl;
    return 0;
}