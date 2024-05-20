//La respuesta es la solve3
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> res;
vector<vector<ll>> dp;

ll solve3(tuple<int, int> pos){
    int x = get<0>(pos), y = get<1>(pos);
    if(x == 0){
        return 0;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    ll min = LLONG_MAX;
    for(int j = 0; j < x; j++){
        ll s1 = res[x][y] + solve3(make_tuple(j, y)) + solve3(make_tuple(x - j - 1, j + 1 + y));
        if(s1 < min){
            min = s1;
        }
    }
    dp[x][y] = min;
    return min;
}

ll solve2(vector<ll> v){
    if(v.size() == 1){
        return 0;
    }
    vector<ll> a = v;
    ll min = LLONG_MAX;
    ll sum;
    int pos = 0;
    for(auto it = v.begin(); it != v.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    for(int j = 1; j < v.size(); j++){
        sum = 0;
        a = v;
        //cout << j << ": " << a[j - 1] << " " << a[j] << endl;
        a[j] = a[j] + a[j - 1];
        a.erase(a.begin() + j - 1);
        
        sum = v[j - 1] + v[j] + solve2(a);
        if(sum < min){
            min = sum;
        }
    }
    return min;
}

vector<vector<ll>> make_tree(vector<ll> v, vector<ll> d){
    vector<vector<ll>> res;
    vector<ll> aux;
    res.push_back(d);
    for(int i = 1; i < v.size(); i++){
        aux.clear();
        for(int j = i; j < v.size(); j++){
            if(j == i){
                aux.push_back(v[j]);
            }else{
                aux.push_back(v[j] - v[j-i-1]);
            }
        }
        res.push_back(aux);
    }
    return res;
}

int main(){
    int N;
    vector<ll> v, v1;
    //freopen("input.txt", "r", stdin);
    cin >> N;
    ll acum = 0;
    for(int j = 0; j < N; j++){
        ll a;
        cin >> a;
        acum += a;
        v.push_back(a);
        v1.push_back(acum);
    }
    res = make_tree(v1, v);
    for (const auto& vec : res) {
        vector<ll> aux;
        aux.clear();
        for(ll num:vec){
            aux.push_back(-1);
        }
        dp.push_back(aux);
    }
/*
    for (const auto& vec : res) {
        for(ll num:vec){
            cout << num << " ";
        }
        cout << endl;
    }
*/

    cout << solve3(make_tuple(N - 1, 0)) << endl; 
/*
    for (const auto& vec : dp) {
        for(ll num:vec){
            cout << num << " ";
        }
        cout << endl;
    }
*/
}
