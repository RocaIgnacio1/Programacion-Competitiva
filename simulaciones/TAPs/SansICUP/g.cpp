#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)

int main(){
    int N;
    int H[3000];
    int maxPos = 0;
    vector<int> ans;

    cin >> N;
    forn(i, N){
        cin >> H[i];
        if (H[i] >= H[maxPos]) {
            maxPos = i;
        }
    }

    int maxH = -1;
    forn(i, maxPos){
        maxH = max(maxH, H[i]);
        ans.push_back(maxH + 1);
    }

    vector<int> rAns;
    maxH = -1;
    for (int i = N-1; i >= maxPos; i--) {
        maxH = max(maxH, H[i]);
        rAns.push_back(maxH + 1);
    }
    reverse(rAns.begin(), rAns.end());

    for(auto a : rAns) {
        ans.push_back(a);
    }

    for(auto a : ans){
        cout << a << " ";
    }
    cout << endl;
}
