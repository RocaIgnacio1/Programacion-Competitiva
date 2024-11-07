#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int n, k;
map<vector<int>,int> compus;

void subconjuntos(vector<int> &nums, vector<int> &vacio, int pos, bool condicion) {
   if(pos==nums.size()){
        if(condicion)compus[vacio]++;
        else{
            compus[vacio]--;
            if(compus.count(vacio)==0)compus.erase(vacio);
        }
        return;
   }

   vacio.pb(nums[pos]);
   subconjuntos(nums, vacio, pos+1, condicion);
   vacio.pop_back();
   while(pos<nums.size()-1 && nums[pos+1]==nums[pos])pos++;
   subconjuntos(nums, vacio, pos+1, condicion);

}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   

    cin >> n >> k;
    int maquina = 1;
    map<int,vector<int>> cola;

    forn(i,n){
        char a;
        cin >> a;
        
        if(a == 'C'){
            int r;
            cin >> r;
            vector<int> nums;
            forn(j,r){
                int v;
                cin >> v;
                nums.pb(v);
            }
            sort(nums.begin(),nums.end());
            cola[maquina] = nums;
            maquina++;

            vector<int> temporal;
            subconjuntos(nums, temporal, 0, true);

            
        }else{
            if(a == 'D'){
                int p;
                cin >> p;
                vector<int> temporal;
                vector<int> nums = cola[p];
                subconjuntos(nums, temporal, 0, false);
                cola.erase(p);
            }else{
                int r;
                cin >> r;
                vector<int> nums;
                forn(j,r){
                    int v;
                    cin >> v;
                    nums.pb(v);
                }
                sort(nums.begin(),nums.end());
                
                if(compus.count(nums)>0){
                    cout << compus[nums] << endl;
                }else cout << 0 << endl;
                
            }
        }
        /*
        cout << endl << endl;
        for (auto i : compus) {
                for (auto a : i.first) {
                    cout << a << " ";
                }
                cout << " cantidad:" << i.second << endl;
        }
        */
        
        
        
    }

    
    return 0;
}
