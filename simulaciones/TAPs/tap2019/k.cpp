#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

vector<int> ddp, jdp;
int n;

bool sortbysfirst(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

void findMax(vector<pair<int, int>> &d, vector<pair<int,int>> &j){
    int maxi = 0;
    for(auto i: d){
        maxi = max(maxi, i.second);
        ddp.push_back(maxi);
    }
    maxi = 0;
    for(auto i: j){
        maxi = max(maxi, i.second);
        jdp.push_back(maxi);
    }
}

int medio(vector<pair<int, int>> &d, vector<pair<int,int>> &j, vector<int> &dp){
    int maxi = 0;
    forn(i, d.size()){
            int left = 0, right = j.size() - 1;
            int mid = (left + right)/2;
            while(left <= right){
                if(d[i].first < j[mid].first){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
                mid = (left + right)/2;
            }
            if(d[i].first < j[mid].first){
                    mid--;
            }
            if(mid >= 0) {
                if(dp[mid] >= d[i].second){
                maxi = max(maxi, d[i].second - d[i].first);
                //cout << d[i].first << " " << d[i].second << endl;
                }else{
                    maxi = max(maxi, dp[mid] - d[i].first);
                    //cout << d[i].first << " " << j[mid].second << endl;
                }
            }
        }
    return maxi;
}

int main(){
    //freopen("input.txt","r",stdin);
    vector<pair<int, int>> d, j;
    cin >> n;
    forn(i, n){
        char p;
        int l, r;
        cin >> p >> l >> r;
        if(p == 'D'){
            d.push_back(make_pair(l, r));
        }
        if(p == 'J'){
            j.push_back(make_pair(l, r));
        }
    }
    sort(d.begin(), d.end(), sortbysfirst);
    sort(j.begin(), j.end(), sortbysfirst);
    findMax(d, j);  
    int maxi = 0;
    maxi = max(maxi, medio(d,j,jdp));
    maxi = max(maxi, medio(j,d,ddp));
    cout << maxi << endl;
}
