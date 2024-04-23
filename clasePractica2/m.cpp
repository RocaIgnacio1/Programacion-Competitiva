#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (){
    int t,n,x;
    //freopen("input.txt", "r", stdin);
    cin >> t;


    for (int i=0; i<t; i++){
        cin >> n >> x;
        int num;
        vector<int> col = {};
        for(int j=0; j<n; j++){
            cin >> num;
            col.push_back(num);         
        }

        std::sort(col.begin(), col.end());
        ll huecos = 0;
        int j=1;
        int ban = 0;
        for(; j < col.size(); j++){
            if(col[j] != col[j-1]){
                
                ll aux = huecos;
                huecos = huecos + (ll)(col[j] - col[j-1]) * j;
                if(huecos > x){
                    ban = 1;
                    int res = ((x - aux) / j) + col [j-1];
                    cout << res << endl;
                    break;
                }
            }
        }
        if (ban == 0){
            int res = ((x - huecos) / j) + col [j-1];
            cout << res << endl;
        }
        
        

    }
   

    return 0;
}