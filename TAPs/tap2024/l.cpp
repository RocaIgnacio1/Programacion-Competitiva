#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)

#ifdef EBUG
//local
#else
//judge
#endif

bool find(vector<int> &a, int n){
    for(auto i : a){
        if (i == n){
            return true;
        }
    }
    return false;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    vector<int> A;
    vector<int> sum_imps;
    vector<int> sum_pots;
    vector<int> cant_unos;
    vector<int> pots;
    int N, Q;
    int sum_pot = 0;
    int sum_imp = 0;
    int cant_uno = 0;
    cin >> N >> Q;

    int n = 1;
    while(n < 10000){
        n *= 2;
        pots.push_back(n);
    }

    sum_imps.push_back(0);
    sum_pots.push_back(0);
    cant_unos.push_back(0);
    forn(i, N){
        int a;
        cin >> a;
        A.push_back(a);
        if ((a % 2 != 0) && a != 1){
            sum_imp += a;
        }
        if (find(pots, a) && a != 1){
            sum_pot += a;
        }
        if (a == 1){
            cant_uno += 1;
        }

        cant_unos.push_back(cant_uno);
        sum_imps.push_back(sum_imp);
        sum_pots.push_back(sum_pot);
    }

    while(Q--){
        int L, R, unos;
        cin >> L >> R; L--;
        int pots, imps;

        pots = sum_pots[R] - sum_pots[L];
        imps = sum_imps[R] - sum_imps[L];
        unos = cant_unos[R] - cant_unos[L];
        //cout << pots << " " << imps << " " << unos << endl;

        if (unos % 2 != 0){
            pots += 1;
        }

        if (pots > imps){
            cout << "A" << endl;
        }else if(imps > pots){
            cout << "B" << endl;
        }else{
            cout << "E" << endl;
        }
    }

    
    return 0;
}