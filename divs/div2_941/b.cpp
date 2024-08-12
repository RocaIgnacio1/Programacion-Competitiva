#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n, m;
    //freopen("input.txt", "r", stdin);
    cin >> t;
    for(int w = 0; w < t; w++){
        cin >> n >> m;
        char a[500][500];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int arriba=0;
        int abajo=0;
        int izquierda=0;
        int derecha=0;
        int arriba2=0;
        int abajo2=0;
        int izquierda2=0;
        int derecha2=0;
        for(int j = 0; j < m; j++){
                if(a[0][j] == 'W'){
                    arriba++;
                }
                if(a[0][j] == 'B'){
                    arriba2++;
                }
        }
        for(int j = 0; j < m; j++){
                if(a[n-1][j] == 'W'){
                    abajo++;
                }
                if(a[n-1][j] == 'B'){
                    abajo2++;
                }
        }
        for(int i = 0; i < n; i++){
                if(a[i][0] == 'W'){
                    izquierda++;
                }
                if(a[i][0] == 'B'){
                    izquierda2++;
                }
        }
        for(int i = 0; i < n; i++){
                if(a[i][m-1] == 'W'){
                    derecha++;
                }
                if(a[i][m-1] == 'B'){
                    derecha2++;
                    
                }
        }

        if((arriba > 0 && abajo > 0 && izquierda > 0 && derecha > 0) or (arriba2 > 0 && abajo2 > 0 && izquierda2 > 0 && derecha2 > 0)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
