#include <bits/stdc++.h>
using namespace std;

vector<int> dpa;
vector<int> dpb;
vector<int> dpc;

int felicidad( int n, int *a, int *b, int *c, int i, char last){
    
    if(last == 'a' && dpa[i] != -1) return dpa[i];
    else if (last == 'b' && dpb[i] != -1) return dpb[i];
    else if (last == 'c' && dpc[i] != -1) return dpc[i];

    if(i == n-1){
        if(last == ' ')  return max({ a[i],b[i], c[i] });

        if(last == 'a')  return max( b[i], c[i]);

        if(last == 'b')  return max( a[i], c[i]);

        if(last == 'c')  return max( a[i], b[i]);
    }

    if(i == 0){
        return max( felicidad(n,a,b,c,i+1,'a')+a[i],   max(felicidad(n,a,b,c,i+1,'b')+b[i], felicidad(n,a,b,c,i+1,'c')+c[i])    );
    }

    if(last == 'a'){
        dpa[i] = max( felicidad(n,a,b,c,i+1,'b')+b[i], felicidad(n,a,b,c,i+1,'c')+c[i]);
        return dpa[i];
    }

    if(last == 'b'){
        dpb[i] = max( felicidad(n,a,b,c,i+1,'a')+a[i], felicidad(n,a,b,c,i+1,'c')+c[i]);
        return dpb[i];
    }

    if(last == 'c'){
        dpc[i] = max( felicidad(n,a,b,c,i+1,'a')+a[i], felicidad(n,a,b,c,i+1,'b')+b[i]);
        return dpc[i];
    }

}



int main(){

    int n;

    //freopen("input.txt", "r", stdin);
    cin >> n;
    int a[100000], b[100000], c[100000];

    for(int i=0; i<n; i++){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    int i = 0;
    char last = ' ';
    dpa.assign(n, -1);
    dpb.assign(n, -1);
    dpc.assign(n, -1);
    cout << felicidad(n,a,b,c,i,last) << endl;
    return 0;
}