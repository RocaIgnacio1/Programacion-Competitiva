#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)


int main(){
    //freopen("input.txt","r",stdin);
    int N;
    string s;
    map<char, int> occurs;

    cin >> N;
    cin >> s;

    occurs['P'] = 0;
    occurs['N'] = 0;
    occurs['I'] = 0;
    for(char c : s){
        occurs[c]++;
    }

    if(occurs['P'] > occurs['N'] + occurs['I']){
        cout << "SI" << endl;
    }else if(occurs['N'] >= occurs['P'] + occurs['I']){
        cout << "NO" << endl;
    }else{
        cout << "INDECISOS" << endl;
    }

    return 0;
}