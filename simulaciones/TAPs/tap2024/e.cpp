#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << " "

using namespace std;

struct Arma{
    int A, B, C;
};
vector<Arma> armas;

bool ord(const Arma &a, const Arma &b) {
    return a.B + b.B * a.A < b.B + a.B * b.A;
}

int dp[205][100005];
int solve(int i, int P){
    if(P < 0 || i >= armas.size()) return 0;
    if (dp[i][P] != -1) return dp[i][P]; 
    Arma a = armas[i];
 
    int max_danio = solve(i + 1, P);
    if (P >= a.B){
        int newP = (P - a.B) / a.A;
        max_danio = max(solve(i + 1, newP) + a.C, max_danio);
    }
 
    return dp[i][P] = max_danio;
}

int main(){
    int N, P;
    memset(dp, -1, sizeof(dp));
    cin >> N >> P; 

    forn(i, N){
        int a, b, c;
        cin >> a >> b >> c;
        armas.push_back(Arma{a, b, c});
    }

    sort(armas.begin(), armas.end(), ord);

    int ans = solve(0, P);
    cout << ans << '\n';

    return 0;
}
