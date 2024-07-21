#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

ll mult(string aux){
    string s;
    bool ban = true;
    for(auto i : aux){
        if(!ban || i != '0'){
            ban = false;
            s.push_back(i);
        }
    }
    ll mul = 1;
    for(auto i : s){
        int aux = i - '0';
        mul *= aux;
    }
    return mul;
}

int main(){
    string s;
    ll n;
    cin >> s;
    ll mul = 1;
    ll max = 0;
    if(s.size() == 1){
        cout << s << endl;
        return 0;
    }
    bool comp = true;
    forn(i, s.size() - 1){
        int len = s.size();
        ll mul = mult(s);
        if(max < mul && comp){
            max = mul;
        }
        if(s[len - 2 - i] == '0'){
            comp = false;
        }else{
            comp = true;
            s[len - 2 - i] = s[len - 2 - i] - 1;
        }
        s[len - 1 - i] = '9';

    }
    mul = mult(s);
    if(max < mul && comp){
            max = mul;
    }
    cout << max << endl;
    

}