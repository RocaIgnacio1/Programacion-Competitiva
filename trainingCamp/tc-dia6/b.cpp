#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

int main(){
    //freopen("input.txt", "r", stdin);
    ll b,d,s;
    cin >> b >> d >> s;

    if(b==0&&d==0){
        cout << 2*(s-1) << endl;
        return 0;
    }
    if(b==0&&s==0){
        cout << 2*(d-1) << endl;
        return 0;
    }

    if(d==0&&s==0){
        cout << 2*(b-1) << endl;
        return 0;
    }

    if(b==d && d==s){
        cout << 0 << endl;
        return 0;
    }

    if(b>d && b>s){
        cout << (b-1)-d + (b-1)-s << endl;
        return 0;
    }

    if(d>b && d>s){
        cout << (d-1)-b + (d-1)-s << endl;
        return 0;
    }

    if(s>b && s>d){
        cout << (s-1)-b + (s-1)-d << endl;
        return 0;
    }

    if(b==d){
        cout << (b-1)-s << endl;
        return 0;
    }
    if(b==s){
        cout << (b-1)-d << endl;
        return 0;
    }
    if(d==s){
        cout << (d-1)-b << endl;
        return 0;
    }
    
}