#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    forn(i, t){
        string s;
        cin >> s;

        int count = 0;
        int maxL = 0;
        for(char c : s){
            if (c == 'L'){
                count ++;
            }else{
                maxL = max(count, maxL);
                count = 0;
            }
        }
        maxL = max(count, maxL);
        cout << maxL +1 << endl;
    }
}