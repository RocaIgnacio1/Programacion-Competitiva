#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        lli n, k;
        cin >> n >> k;

        deque<lli> a(n);
        for (lli j = 0; j < n; j++){
            cin >> a[j];
        }

        bool left = true;

        while (k > 0 && !a.empty()){         
            auto actual = left ? a.begin() : a.end() - 1;
            auto otro   = left ? a.end() - 1 : a.begin();

            if (a.size() == 1){
                k -= *actual;
                if (k >= 0){
                    a.pop_back(); 
                }
                break;
            }

            if (*actual > *otro){
                k -= *otro * 2;
                if (k >= 0){
                    *actual -= *otro;
                    left ?  a.pop_back() : a.pop_front();
                }
            }else{
                k -= *actual * 2 -1;
                if (k >= 0){
                    *otro -= *actual - 1;
                    left ?  a.pop_front() : a.pop_back();
                }
                left = !left;
            }   
        }


        cout << n - a.size() << endl;
    }
    
    return 0;
}