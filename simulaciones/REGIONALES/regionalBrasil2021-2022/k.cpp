#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;
#ifdef EBUG
//local
#else
//judge
#endif

string uniq(string &s){
    set<char> st;
    string res;
    forn(i, s.size()){
        st.insert(s[i]);
    }

    for(auto i: st){
        res.push_back(i);
    }
    return res;
}
bool solve(string a, string b){
    auto it = a.begin();
    for(auto i: b){
        if(*it == i) it++;
        if(it == a.end()) return true;
    }
    if(it == a.end()) return true;
    return false;
}
int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<string> v;
    string aux;
    forn(i, n){
        string s;
        cin >> s;
        aux.push_back(s[0]);
        sort(s.begin(), s.end());
        v.push_back(uniq(s));
    }
    sort(aux.begin(), aux.end());
    aux = uniq(aux);
    forn(i, n){
        if(solve(v[i], aux)){
            cout << "Y" << endl;
            return 0;
        }
    }
    cout << "N" << endl;
}