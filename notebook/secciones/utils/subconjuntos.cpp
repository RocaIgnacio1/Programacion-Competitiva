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


void subconjuntos(vector<int> &nums, vector<int> &vacio, int pos) {
   if(pos==nums.size()){
        for(auto i: vacio){
            cout << i << " ";
        }
        cout << endl;
        return;
   }
   vacio.pb(nums[pos]);
   subconjuntos(nums, vacio, pos+1);
   vacio.pop_back();
   while(pos<nums.size()-1 && nums[pos+1]==nums[pos])pos++;
   subconjuntos(nums, vacio, pos+1);
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   

    vector<int> nums{1,3,6,9};
    vector<int> vacio;
    subconjuntos(nums, vacio, 0);
    
    /*
        Salida:
            1 3 6 9 
            1 3 6 
            1 3 9 
            1 3   
            1 6 9 
            1 6
            1 9
            1
            3 6 9
            3 6
            3 9
            3
            6 9
            6
            9
    */
    return 0;
}
