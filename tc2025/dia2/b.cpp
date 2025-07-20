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

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    int m[4][4];
    forn(i,4){
        forn(j,4){
            m[i][j]=0;
        }
    }
    forn(k,s.size()){
        if(s[k]=='1'){
            bool ban=false;
            forn(i,4){
                if(ban)break;
                if(m[i][1]==0 && m[i][2]==0){
                    m[i][1] = 1;
                    m[i][2] = 1;
                    cout << i+1 << " " << 2 << endl;
                    ban=true;
                }
            }
        }else{
                if(m[0][0]==0 && m[1][0]==0){
                    m[0][0] = 1;
                    m[1][0] = 1;
                    cout << 1 << " " << 1 << endl;
                }else{
                    if(m[2][0]==0 && m[3][0]==0){
                        m[2][0] = 1;
                        m[3][0] = 1;
                        cout << 3 << " " << 1 << endl;
                    }else{
                        if(m[0][3]==0 && m[1][3]==0){
                        m[0][3] = 1;
                        m[1][3] = 1;
                        cout << 1 << " " << 4 << endl;
                        }else{
                            if(m[2][3]==0 && m[3][3]==0){
                                m[2][3] = 1;
                                m[3][3] = 1;
                                cout << 3 << " " << 4 << endl;
                            }
                        }
                    
                    }
                }
        }
    

        forn(i,4){
            if(m[i][0]==1 && m[i][1]==1 && m[i][2]==1 && m[i][3]==1){
                m[i][0]=0;
                m[i][1]=0;
                m[i][2]=0;
                m[i][3]=0;
            }
        }
        forn(j,4){
            if(m[0][j]==1 && m[1][j]==1 && m[2][j]==1 && m[3][j]==1){
                m[0][j]=0;
                m[1][j]=0;
                m[2][j]=0;
                m[3][j]=0;
            }
        }
        /*
        forn(i,4){
            forn(j,4){
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << endl;
        */
    }
    return 0;
}