#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define modsum(a, b) ((a%M + b%M)%M)

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

struct Project {
    ll a;
    ll b;
    ll p;
    bool operator<(Project p){
        return a < p.a;
    }
    bool operator<(ll aa){
        return a < aa;
    }
    void print() {
        cout << a << ", " << b << ": " << p << endl;
    }
};


bool operator<(ll a, Project b){
    return a < b.a;
}

const int MAXN = 2*1e5+1;

ll dp[MAXN];
int n;
vector<Project> projects;

int search_pos_greater(ll b) {
    auto it = upper_bound(projects.begin(), projects.end(), b);
    if ((*it).a == b) {
        it = next(it);
    }

    if (it == projects.end()) return -1;

    return int(distance(projects.begin(), it));
}

ll solve(int i) {
    if (i >= n-1) return projects[i].p;
    if (dp[i] != -1) return dp[i];

    Project p = projects[i];

    ll ans = 0;
    int j = search_pos_greater(p.b);
    ans = solve(i+1);
    if (j != -1) {
        ans = max(ans, p.p + solve(j));
    }else{
        ans = max(ans, p.p);
    }

    return dp[i] = ans;
}

void print() {
    for(auto p : projects){
        cout << p.a << ", " << p.b << ": " << p.p << endl;
    }
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    forn(i, n){
        ll a, b, p;
        cin >> a >> b >> p;
        projects.push_back({a, b, p});
    }
    memset(dp, -1, sizeof(dp));

    sort(projects.begin(), projects.end());

    cout << solve(0) << endl;
}
