#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   int n, k;
   vector<int> num, col;
   cin >> n >> k;
   forn(i, n){
    int C, N;
    cin >> N >> C;
    num.push_back(N);
    col.push_back(C);
   }
   bool res = true;
   forn(i, n){
    if(col[i] != col[num[i]-1]){
        res = false;
        //cout << i << " " << num [i] - 1 << endl;
    } 
   }
    if(res){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
    return 0;
}