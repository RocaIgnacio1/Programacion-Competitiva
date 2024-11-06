#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

double maximo(double a, double b){
    if(a>b) return a;
    else return b;
}

char t[7][24];
int d, h;
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    forn(i,7){
        forn(j,24){
            cin >> t[i][j];
        }
    }
    cin >> d >> h;
    vector<int> dias = {1,2,3,4,5,6,7};
    vector<bool> mask(dias.size(),false);
    fill(mask.begin(),mask.begin()+d,true);
    double ans = 0;
    do{
        vector<int> cant;
        forn(i,24)cant.pb(0);
        forn(i,dias.size()){
            if(mask[i]){

                forn(j,24){
                    if(t[i][j]=='.')cant[j]++;
                }

            }
        }
        
        sort(cant.begin(),cant.end());
        reverse(cant.begin(),cant.end());
        
        double sum=0;
        forn(i,h){
            sum=sum+cant[i];
        }
        ans = maximo(ans, double(sum / (d*h)));
    }while (prev_permutation(mask.begin(),mask.end()));

    cout << fixed << setprecision(9) << ans << endl;

}