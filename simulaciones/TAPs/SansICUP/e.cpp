#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)

int main(){
    int N, S, K;
    vector<int> A;
    cin >> S >> N >> K;

    int cols = 0;

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int mask = 1; mask < (1 << K); ++mask) {
        vector<int> subset;
        for (int i = 0; i < K; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(A[i]);
            }
        }
        
        // lcm of all the subset
        long long current_lcm = S;
        for (int num : subset) {
            current_lcm = lcm(current_lcm, num);
            if (current_lcm > N) {
                break;
            }
        }        

        int m = subset.size();
        long long count = N / current_lcm;
        if (m % 2 == 1) {
            cols += count;
        } else {
            cols -= count;
        }
    }

    int total = N/S;
    cout << total - cols << endl;
}
