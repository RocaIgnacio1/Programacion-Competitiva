#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)

#ifdef EBUG
//local
#else
//judge
#endif

map<int, int> bloqueados[9], mebloquea[9];
// vacia v
// x xavier
// o olivia
// b bloqueada

string desbloquear(int n, string s){
    for(auto i : bloqueados[n]){
        mebloquea[i.first].erase(n);
        if(mebloquea[i.first].empty()){
            s[i.first] = 'V';
        }
    }
    return s;
}

string bloquear(int n, string s){
    for(auto i : bloqueados[n]){
        mebloquea[i.first][n] = 1;
        s[i.first] = 'B';
    }
    return s;
}

char quienGana(string s){
    if(s[0] != 'B' && s[0] != 'V' && s[0] == s[3] && s[0] == s[6]) return s[0];
    if(s[1] != 'B' && s[1] != 'V' && s[1] == s[4] && s[1] == s[7]) return s[1];
    if(s[2] != 'B' && s[2] != 'V' && s[2] == s[5] && s[2] == s[8]) return s[2];
    if(s[0] != 'B' && s[0] != 'V' && s[0] == s[1] && s[0] == s[2]) return s[0];
    if(s[3] != 'B' && s[3] != 'V' && s[3] == s[4] && s[3] == s[5]) return s[3];
    if(s[6] != 'B' && s[6] != 'V' && s[6] == s[7] && s[6] == s[8]) return s[6];
    if(s[0] != 'B' && s[0] != 'V' && s[0] == s[4] && s[0] == s[8]) return s[0];
    if(s[2] != 'B' && s[2] != 'V' && s[2] == s[4] && s[2] == s[6]) return s[2];
    return 'N';
}

char solve(string s, char turno){
    char q = quienGana(s);
    //cout << s << " " << turno << endl;
    //cout << q << endl;
    if(q != 'N'){
        return q;
    }
    bool ban = true;
    for(auto i : s){
        if(i == 'V'){
            ban = false;
        }
    }
    if(ban) return 'E';
    char nturno;
    if(turno == 'X') nturno = 'O';
    if(turno == 'O') nturno = 'X';
    int cone = 0, conx = 0, cono = 0;
    forn(i, 9){
        if(s[i] == 'V'){
            string aux = s;
            aux[i] = turno;
            aux = desbloquear(i, aux);
            char res = solve(aux, nturno);
            aux = bloquear(i, aux);
            if(res == 'E') cone++;
            if(res == 'X') conx++;
            if(res == 'O') cono++;
        }
    }
    if(turno == 'X'){
        if(conx > 0) return 'X';
        if(cone > 0) return 'E';
        return 'O';
    }
    if(turno == 'O'){
        if(cono > 0) return 'O';
        if(cone > 0) return 'E';
        return 'X';
    }
    return 'F';
}


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    string s;
    cin >> n;
    forn(i, n){
        int x, y;
        cin >> x >> y;
        bloqueados[x-1][y-1] = 1;
        mebloquea[y-1][x-1] = 1;
    }
    forn(i, 9){
        if(mebloquea[i].size() == 0){
            s.push_back('V');
        }else{
            s.push_back('B');
        }
    }
    //cout << s << endl;
    cout << solve(s, 'X') << endl;
}