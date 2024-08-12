#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define print()

vector<ll> nums;

int search(ll n){
    int l = 0;
    int r = nums.size() - 1;
    while(r >= l){
        int mid = (l+r) / 2;
        if (nums[mid] == n){
            return mid;
        }

        if (n > nums[mid]){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> pows(20);

    pows[0] = 2;
    for(int i = 1; i <= 20; i++){
        pows[i] = 2 * pows[i-1];
    }

    forn(i, n){
        ll a;
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());

    int maxSize = 0;
    vector<ll> res;
    for(ll n : nums){
        vector<ll> maxs;
        maxs.push_back(n);
        for(int i : pows){
            int pos;
            pos = search(n+i);
            if (pos != -1){
                maxs.push_back(nums[pos]);
            }
            pos = search(n-i);
            if (pos != -1){
                maxs.push_back(nums[pos]);
            }
        }

        cout << n << ": ";
        for(ll i : maxs){
            cout << i << " ";
        }
        cout << endl;

        if(maxs.size() > maxSize){
            maxSize = maxs.size();
            res = maxs;
        }
    }

    cout << res.size() << endl;
    for(ll i : res){
        cout << i << " ";
    }
    cout << endl;
}