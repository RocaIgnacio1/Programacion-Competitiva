#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int n, m, q;
int k, a, b;
map<int, vector<int>> v;

string bs(int val, int pte){

    if(v.count(pte) == 0) return "NO";
    int l = 0, r = v[pte].size() - 1, mid;
    mid = (l+r)/2;
    while(l<=r){
        if(val <= v[pte][mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
        mid = (l+r)/2;
    }
    if(val <= v[pte][mid]){
        mid --;
    }
    if(mid == v[pte].size() - 1) return "NO";
    //cout << mid << " " << v[pte][mid + 1];
    if(mid % 2 == 0 || v[pte][mid+1] == val) return "SI";
    return "NO";
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m >> q;
    int con = 0;
    vector<int> K, A, B;
    array<vector<int>, 10002> vec;
    map<int, vector<int>> pos;
    forn(i, m){
        int aux;
        cin >> k >> a >> b;
        pos[b-a].push_back(a);
        pos[b-a].push_back(a+k);
    }
    for (const auto& p : pos) {
        vector<int> aux = p.second;
        sort(aux.begin(), aux.end());
        pos[p.first] = aux;
    }
    for (const auto& p : pos) {
        int con = 1;
        fora(1,i,p.second.size()){
            if(p.second[i] == p.second[i-1]){
                con++;
            }else{
                if(con%2 == 1){
                    v[p.first].push_back(p.second[i-1]);
                }
                con = 1;
            }
        }
        if(con%2 == 1){
            v[p.first].push_back(p.second[p.second.size()-1]);
        }
    }
    /*
    for (const auto& p : v) {
        cout << p.first << ": ";
        for(auto i: p.second){
            cout << i << " ";
        }
        cout << endl;
    }
    */
    forn(i, q){
        cin >> a >> b;
        int maxi = max(a, b);
        int mini = min(a, b);
        cout << bs(mini, maxi-mini) << endl;
    }
    
}