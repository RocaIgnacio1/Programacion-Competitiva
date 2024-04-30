#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int t;

cin >> t;
for(int j = 0; j < t; j++){
    int n, k;
    map<int, int> a;
    vector<int> b;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        a[p]++;
    }
    for(int i = 0; i < a.size(); i++){
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end()); 
    int cant_cartas = n;

    
    for(int i = 0; b[b.size() - 1] >= k ; i++){
            b[b.size()-1] = b[b.size()-1] - k;
            sort(b.begin(), b.end());
            int l = k - 1;
            for(int con = b.size() - 1; l > 0; con--){
                if(b[con] < k){
                    int aux = k - b[con];
                    if(aux <= l){
                        b[con] = b[con] + aux;
                    }else{
                        b[con] = b[con] + l;
                    }
                    l = l - aux;
                }
            }
            cant_cartas --;
    }
    cout << cant_cartas << endl;

}
}