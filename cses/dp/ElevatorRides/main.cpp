#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

typedef pair<int, int> ii;

const int INF = INT_MAX;

std::string bstring(int n){
    std::string s;
    for(int m = sizeof(n) * 8;m--;){
            s.push_back('0'+((n >> m) & 1));
    }
    return s;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int max = 1<<n;
    int weights[n];
    vector<ii> dp; // rides, remainder
    dp.assign(max, {INF, x});
    dp[0] = {0, 0};

    forn(i, n){
        cin >> weights[i];
    }

    forn(mask, max){
        auto [rides, remainder] = dp[mask];
        forn(i, n){
            if (!(mask & (1 << i))) { // if the Wi its no added to the group
                int new_mask = mask | (1 << i); // add Wi to the group
                int w = weights[i];
                /*cout << bstring(mask) << endl;*/

                ii value;
                if (w <= remainder) {
                    value = {rides, remainder - w};
                } else { // create new ride
                    value = {rides + 1, x - w};
                }

                /*cout << value.first << ", " << value.second << endl;*/
                // check if the value its better
                if (
                    value.first < dp[new_mask].first || // new_rides < rides
                   (value.first == dp[new_mask].first && value.second > dp[new_mask].second) // new_remainder > remainder
                ) {
                    dp[new_mask] = value;
                }
            }
        }
    }

    cout << dp[max-1].first << endl;
}
