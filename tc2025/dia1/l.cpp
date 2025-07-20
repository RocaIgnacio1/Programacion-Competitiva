#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define ll long long

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    srand(static_cast<unsigned int>(time(NULL)));

    int t;
    cin >> t;
    forn(i, t){
        int n; cin >> n;
        vector<int> points = {1, 2, 3};
    
        forn(j, 76){
            cout << "? " << points[0] << " " << points[1] << " " << points[2] << endl;
            fflush(stdout);
            int resp; cin >> resp;
            if(resp==0){
                cout << "! " << points[0] << " " << points[1] << " " << points[2] << endl;
                fflush(stdout);
                break;
            }else{
                int r = (rand() % 3);
                points[r] = resp;
                if(resp==-1){
                    return 0;
                }
                r=resp;
            }
        }
    }
    
    return 0;
}