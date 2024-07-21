#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define mos(v) forn(auto i : v) cout << i << " ";

string a1 = "***", b1 =  "***", c1 = "***", d1 = "***", e1 = "***";
string a2 = "*.*", b2 =  "*.*", c2 = "*..", d2 = "*.*", e2 = "*..";
string a3 = "***", b3 =  "***", c3 = "*..", d3 = "*.*", e3 = "***";
string a4 = "*.*", b4 =  "*.*", c4 = "*..", d4 = "*.*", e4 = "*..";
string a5 = "*.*", b5 =  "***", c5 = "***", d5 = "***", e5 = "***";
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(auto i: s){
        if(i == 'A'){
            cout << a1 << "";
        }
        if(i == 'B'){
            cout << b1 << "";
        }
        if(i == 'C'){
            cout << c1 << "";
        }
        if(i == 'D'){
            cout << d1 << "";
        }
        if(i =='E'){
            cout << e1 << "";
        }
    }
    cout << endl;
    for(auto i: s){
        if(i == 'A'){
            cout << a2 << "";
        }
        if(i == 'B'){
            cout << b2 << "";
        }
        if(i == 'C'){
            cout << c2 << "";
        }
        if(i == 'D'){
            cout << d2 << "";
        }
        if(i == 'E'){
            cout << e2 << "";
        }
    }
    cout << endl;
    for(auto i: s){
        if(i =='A'){
            cout << a3 << "";
        }
        if(i == 'B'){
            cout << b3 << "";
        }
        if(i == 'C'){
            cout << c3 << "";
        }
        if(i == 'D'){
            cout << d3 << "";
        }
        if(i == 'E'){
            cout << e3 << "";
        }
    }
    cout << endl;
    for(auto i: s){
        if(i == 'A'){
            cout << a4 << "";
        }
        if(i == 'B'){
            cout << b4 << "";
        }
        if(i == 'C'){
            cout << c4 << "";
        }
        if(i == 'D'){
            cout << d4 << "";
        }
        if(i == 'E'){
            cout << e4 << "";
        }
    }
    cout << endl;
    for(auto i: s){
        if(i == 'A'){
            cout << a5 << "";
        }
        if(i == 'B'){
            cout << b5 << "";
        }
        if(i == 'C'){
            cout << c5 << "";
        }
        if(i == 'D'){
            cout << d5 << "";
        }
        if(i == 'E'){
            cout << e5 << "";
        }
    }
    cout << endl;


    
}