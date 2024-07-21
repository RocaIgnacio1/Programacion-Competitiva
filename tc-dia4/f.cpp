#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

#define MAXN 100010

int main(){
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> aux(m, vector<int>());
    vector<vector<int>> S(m, vector<int>());

    forn(i, n){ 
        int s, r;
        cin >> s >> r;
        aux[s-1].push_back(r);
    }

    forn(i, m){ 
        sort(aux[i].begin(), aux[i].end(), greater<int>());
    }

    forn(i, m){ 
        forn(j, aux[i].size()){
            if (j != 0){   
                S[i].push_back(aux[i][j] + S[i][j-1]);
            }else{
                S[i].push_back(aux[i][j]);
            }
        }
    }
    int maxSize = 0;
    forn(i, m){
        maxSize = max((int)S[i].size(), maxSize);
    }    
    vector<ll> sum(maxSize, 0);

    forn(i, m){
        forn(j, S[i].size()+1){
            if (S[i][j] > 0){
                sum[i] += S[i][j];
            }
        }
    }

    ll maxSum = 0;
    forn(i, sum.size()){
        maxSum = max((int)maxSum, (int)sum[i]);
    }
    cout << maxSum << endl;
}