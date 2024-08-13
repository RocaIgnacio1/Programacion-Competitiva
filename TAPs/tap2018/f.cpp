#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main() {
    //freopen("input.txt","r",stdin);
    int N, M;
    map<int, int> occurs;

    cin >> N >> M;

    forn(i, N){
        int a;
        cin >> a;
        occurs[a]++;
    }
    
    if (occurs.size() == M){
        if (M == 1){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        int c=0;
        for(auto i:occurs){
            c++;
        }
        if(c==1){
            cout << 1 << endl; 
            return 0;
        }
        if(occurs.size()==2 && M==3){
            int c=0, cant1, cant2;
            for(auto i:occurs){
                if(c==0) cant1 = i.second;
                if(c==1) cant2 = i.second;
                c++;
            }
            
            if(cant1!=cant2){
                cout << M-1 << endl;
            }else{
                if(cant1==1){
                    cout << M-2 << endl;
                }else{
                    cout << M << endl;
                }
            }
            return 0;   
            
        }     
        else{
            cout << M << endl;
        }
        
    }

    return 0;
}
