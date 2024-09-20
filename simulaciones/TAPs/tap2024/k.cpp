#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fori(i,n) for(int i = n-1; i >= 0; i--)

#ifdef EBUG
//local
#else
//judge
#endif

vector<string> aux, mat;
bool encontrarT(int f, int c){
    if(mat[f][c] == '.') return false;
    if(mat[f][c+1] == '.') return false;
    if(mat[f][c+2] == '.') return false;
    if(mat[f+1][c+1] == '.') return false;
    if(mat[f+2][c+1] == '.') return false;
    if(mat[f+3][c+1] == '.') return false;
    if(mat[f+4][c+1] == '.') return false;
    return true;
}

void taparT(int f, int c){
    mat[f][c] = '.';
    mat[f][c+1] = '.';
    mat[f][c+2] = '.';
    mat[f+1][c+1] = '.';
    mat[f+2][c+1] = '.';
    mat[f+3][c+1] = '.';
    mat[f+4][c+1] = '.';

}

void taparT2(int f, int c){
    aux[f][c] = '.';
    aux[f][c+1] = '.';
    aux[f][c+2] = '.';
    aux[f+1][c+1] = '.';
    aux[f+2][c+1] = '.';
    aux[f+3][c+1] = '.';
    aux[f+4][c+1] = '.';

}

bool encontrarA(int f, int c){
    if(mat[f][c] == '.') return false;
    if(mat[f][c+1] == '.') return false;
    if(mat[f][c+2] == '.') return false;
    if(mat[f+1][c] == '.') return false;
    if(mat[f+2][c] == '.') return false;
    if(mat[f+3][c] == '.') return false;
    if(mat[f+4][c] == '.') return false;
    if(mat[f+1][c+2] == '.') return false;
    if(mat[f+2][c+2] == '.') return false;
    if(mat[f+3][c+2] == '.') return false;
    if(mat[f+4][c+2] == '.') return false;
    if(mat[f+2][c+1] == '.') return false;
    if(mat[f+1][c+1] == '#') return false; 
    return true;
}

void taparA(int f, int c){
    mat[f][c] = '.';
    mat[f][c+1] = '.';
    mat[f][c+2] = '.';
    mat[f+1][c] = '.';
    mat[f+2][c] = '.';
    mat[f+3][c] = '.';
    mat[f+4][c] = '.';
    mat[f+1][c+2] = '.';
    mat[f+2][c+2] = '.';
    mat[f+3][c+2] = '.';
    mat[f+4][c+2] = '.';
    mat[f+2][c+1] = '.';
}

bool encontrarP(int f, int c){
    if(mat[f][c] == '.') return false;
    if(mat[f][c+1] == '.') return false;
    if(mat[f][c+2] == '.') return false;
    if(mat[f+1][c] == '.') return false;
    if(mat[f+2][c] == '.') return false;
    if(mat[f+3][c] == '.') return false;
    if(mat[f+4][c] == '.') return false;
    if(mat[f+1][c+2] == '.') return false;
    if(mat[f+2][c+2] == '.') return false;
    if(mat[f+2][c+1] == '.') return false;
    if(mat[f+1][c+1] == '#') return false; 
    return true;
}

void taparP(int f, int c){
    mat[f][c] = '.';
    mat[f][c+1] = '.';
    mat[f][c+2] = '.';
    mat[f+1][c] = '.';
    mat[f+2][c] = '.';
    mat[f+3][c] = '.';
    mat[f+4][c] = '.';
    mat[f+1][c+2] = '.';
    mat[f+2][c+2] = '.';
    mat[f+2][c+1] = '.';
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    int a = 0, t = 0, p = 0;
    cin >> n >> m;
    forn(i, n){
        string s;
        cin >> s;
        mat.push_back(s);
    }
    
    fori(i, n-4){
        fori(j, m-2){
            if(encontrarA(i,j)){
                a++;
                taparA(i,j);
            }
        }
        fori(j, m-2){
            if(encontrarP(i,j)){
                p++;
                taparP(i,j);
            }
        }   
        fori(j, m-2){
            if(encontrarT(i,j)){
                t++;
                taparT(i,j);
            }
        }   
    }


    cout << t << " " << a << " " << p << endl;
}