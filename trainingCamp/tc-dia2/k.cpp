#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)

vector<int> a;
vector<int> b;
vector<vector<int>> ans;
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m, k, pos, valor;
    cin >> n;
    
    forn(i,n){
        cin >> valor;
        a.push_back(valor);
    }
    
    b = a;
    ans.push_back(a);
    sort(b.begin(), b.end());
    int con=0;
    forn(w,n){
        fori(j,a.size()){
            if(a[j]==b[con]){
                //b.pop_front();
                a.erase(a.begin()+j);
                ans.push_back(a);
                con++;
                break;
            }
        }
    }
    cin >> m;
    forn(i,m){
        cin >> k >> pos;
        cout << ans[n - k][pos-1] << endl;
    }

    return 0;
}