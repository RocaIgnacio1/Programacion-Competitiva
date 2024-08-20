#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

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

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int Y, N;
    vector<int> x;
    cin >> Y >> N;
    forn(i,Y){
        int val;
        cin >> val;
        x.push_back(val);
    }
    
    forn(i,N){
        int a,p,f;
        cin >> a >> p >> f;

        if (p <= x[a-1]){
            cout << 0 << endl;
            continue;
        }

        if(f>0){
            vector<int> b(x.begin()+a,x.begin()+f+a);
            
            sort(b.begin(), b.end());

            if(p<b[0]){
                cout << b.size() << endl;
                continue;
            }else{
                if(p>b[b.size()-1]){
                    cout << 0 << endl;
                    continue;
                }
            }

            int l = 0, r = b.size() - 1, mid = (l+r)/2;
            while(l <= r){
                if(p < b[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
                mid = (l+r)/2;
            }
            
            if(b[mid]<p){
                mid++;
            }
            cout << b.size()-mid << endl;
        }else{
            cout << 0 << endl;
        }
    }

    return 0;
}