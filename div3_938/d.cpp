#include <bits/stdc++.h>


using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    
    for (int w = 0; w < t; w++){
        
        int n, m ,k;
        cin >> n >> m >> k;
        int rta = 0;
        
        vector<int> a(n);
        std::map<int, int> segmentoA;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        int num;
        std::map<int, int> b;
        for (int j = 0; j < m; j++) {
            std::cin >> num;
            b[num]++;
        }       
        
        int coincidencias=0;
        for (int j = 0; j < m; j++) {
            int num;
            num = a[j];
            segmentoA[num]++;        
            if (b[num] >= segmentoA[num]){
                coincidencias++;
            }
        }

        if(coincidencias>=k){
                rta++;
        }

        for(int z=0; (m+z+1) <= n ; z++){
            
            auto inicio = a.begin() + z;
            auto fin = a.begin() + m + z ;
             
            segmentoA[*inicio]--;
            if(b[*inicio] > segmentoA[*inicio]){
                coincidencias--;
            }

            segmentoA[*fin]++;
            if(b[*fin] >= segmentoA[*fin]){
                coincidencias++;
            }

            if(coincidencias>=k){
                rta++; 
            }
        }
        cout << rta << endl;
    }

    return 0;
}
