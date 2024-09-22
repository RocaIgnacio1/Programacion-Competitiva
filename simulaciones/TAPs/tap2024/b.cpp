#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)

#ifdef EBUG
//local
#else
//judge
#endif

map<int, bool> divban;
vector<int> divs;
void divisores(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            divban[i] = true;
            divban[n/i] = true;
        }
    }
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    forn(i,n){
        if(i==0)continue;
        if(i==1)continue;

        if(n%i==0){
            divs.push_back(i);
            divban[i] == false;
        }
    }
    reverse(divs.begin(), divs.end());
    for(auto a: divs){
        divisores(a);
    }
    int con = 0;
    for(auto a: divs){
        if(divban[a] == false){
            con++;
        }
    }
    if(con == 0){
        cout << 1 << endl << 1 << " " << 1 << endl;
        return 0;
    }
    cout << con << endl;
    for(auto a: divs){
        if(divban[a] == false){
            cout << 1 << " " << a << endl;
        }
    }

    return 0;
}