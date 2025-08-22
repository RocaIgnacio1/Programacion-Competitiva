#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

int main() {
    HOLA;
    #ifdef EBUG
    freopen("input.txt", "r", stdin);
    #endif

    int f;
    cin >> f;
    bool turno = false;
    int acum = 0;
    vector<string> v;
    forn(i,f){
        string s;
        cin >> s;
        bool r,d;
        string q;
        forn(j, s.size()){
            if(s[j] == 'D'){
                if(q.empty()){
                    q.push_back('D');
                }else{
                    if(q.back() == 'R'){
                        q.push_back('D');
                    }
                }
            }

            if(s[j] == 'R'){
                if(q.empty()){
                    q.push_back('R');
                }else{
                    if(q.back() == 'D'){
                        q.push_back('R');
                    }
                }
            }
        }
        v.push_back(q);
    }
    int con = 0;
    int D = 0, R = 0, RD = 0;
    for(auto s: v){
        if(s.empty()) continue;
        bool r = false, d = false;
        if(s[0] == 'R'){
            r = true;
        }
        if(s.back() == 'D'){
            d = true;
        }

        if(r&&d){
            int num = ((s.size()-2)/2);
            con+= num;
            RD++;
        }
        if(r&&!d){
            int num = ((s.size()-1)/2);
            con+= num;
            R++;
        }
        if(!r&&d){
            int num = ((s.size()-1)/2);
            con+= num;
            D++;
        }
        if(!r&&!d){
            con += (s.size()/2);
        }
    }
    if(RD == 0){
        cout << con + min(D, R) << endl;
    }else{
        cout << con + min(D, R) + (D||R) + RD - 1 << endl;
    }
    
    return 0;
}