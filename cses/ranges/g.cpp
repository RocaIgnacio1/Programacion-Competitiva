#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
#else
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
   int n, q;
   cin >> n >> q;
   vector<string> f;
   ll sum[1009][1009];
   forn(i, n){
        string s;
        cin >> s;
        f.push_back(s);
   }
   forn(i, n){
        forn(j, n){
            if(f[i][j] == '*'){
                sum[i][j] = 1;
            }else{
                sum[i][j] =0;
            }
        }
   }
   /* forn(i, n){
        forn(j, n){
            cout << sum[i][j] << " ";
        }
        cout << endl;
   } */
   forn(i, n){
        forn(j, n){
            if(i == 0){
                if(j != 0){
                    sum[i][j] += sum[i][j-1]; 
                }
            }else if(j == 0){
                sum[i][j] += sum[i-1][j]; 
            }else{
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
   }
   forn(i, q){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        if(y1==1 && x1==1) cout << sum[y2-1][x2-1] << endl;
        if(y1==1 && x1>1) cout << sum[y2-1][x2-1] - sum[y2-1][x1-2] << endl;
        if(x1==1 && y1>1) cout << sum[y2-1][x2-1] - sum[y1-2][x2-1] << endl;
        if(x1>1 && y1>1)cout << sum[y2-1][x2-1] - sum[y2-1][x1-2]  - sum[y1-2][x2-1] + sum[y1-2][x1-2] << endl;
   }

}