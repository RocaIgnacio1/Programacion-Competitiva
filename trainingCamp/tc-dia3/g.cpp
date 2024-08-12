#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);

    int N;
    string s;
    cin >> N;
    cin >> s;

    int c = 0;
    forn(i, N){
        int n = s[i]-'0';
        if (n % 2 == 0){
            c += 1+i;
        }
    }
    cout << c << endl;
}