#include <bits/stdc++.h>
using namespace std;

bool ok(int a){
    // funcion que hace algo
    return a>5;
}
int bs(vector<int> &v, int val){
    int l = 0; // algo que siempre sea False
    int r = v.size() - 1; // algo que siempre sea True
    int mid = (l+r)/2;
    while((r-l)>1){
        mid = (l+r)/2;
        if(ok(v[mid])){
            r=mid;
        }else l=mid;
    }
    // FFFFFFFFF TTTTTT
    //         l r
    // r == l+1
    // l == ultimo que No cumple. Ultimo FALSE
    // r == primero que Si cumple. Primer TRUE

    return mid;
}
