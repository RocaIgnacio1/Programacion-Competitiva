#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
#else
#endif

string s;
vector<string> v;

bool esSigno(char c){
    if(c == '*') return true;
    if(c == '+') return true;
    if(c == '-') return true;
    if(c == '/') return true;
    return false;
}

bool esParentesisIzquierdo(char c){
    if(c == '(') return true;
    return false;
}
bool esParentesisDerecho(char c){
    if(c == ')') return true;
    return false;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    cin >> s;
    forn(i, s.size()){
        if(esSigno(s[i])){
            s[i] = '+';
        }else if(!esParentesisDerecho(s[i]) && !esParentesisIzquierdo(s[i])){
            s[i] = 'a';
        }
    }
    string aux;
    aux.push_back(s[0]);
    fora(1, i, s.size()){
        if(s[i] == 'a'){
            if(aux[i] == ')'){
                v.push_back(aux);
                aux.clear();
                aux.push_back(s[i]);
            }
        }
        if(s[i] == '('){
            if(aux[i] == 'a'){
                v.push_back(aux);
                aux.clear();
                aux.push_back(s[i]);
            }
        }
        if(s[i] == ')'){
            if(aux[i] == '+'){
                v.push_back(aux);
                aux.clear();
                aux.push_back(s[i]);
            }
        }
        if(s[i] == '+'){
            if(aux[i] == '('){
                v.push_back(aux);
                aux.clear();
                aux.push_back(s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;
}