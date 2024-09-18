#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
typedef long long ll;

using namespace std;
#define MAXP 1000000  // no necesariamente primo
int criba[MAXP + 1];
vector<int> primos;


void crearCriba() {
  int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
  for (int p = 25; p <= MAXP; p += 10) criba[p] = 5;
  for (int p = 9; p <= MAXP; p += 6) criba[p] = 3;
  for (int p = 4; p <= MAXP; p += 2) criba[p] = 2;
  for (int p = 7, cur = 0; p * p <= MAXP; p += w[cur++ & 7])
    if (!criba[p])
      for (int j = p * p; j <= MAXP; j += (p << 1))
        if (!criba[j]) criba[j] = p;
}

void buscarPrimos() {
  crearCriba();
  forr(i, 2, MAXP + 1) if (!criba[i]) primos.push_back(i);
}

void fact(ll n, map<ll, ll>& f) {  // O (cant primos)
  for (auto p = primos.begin(); p != primos.end(); p++) {
    while (!(n % *p)) {
      f[*p]++;  // divisor found
      n /= *p;
    }
  }
  if (n > 1) f[n]++;
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif

    ll n;
    cin >> n;
    map<ll, vector<ll>> a;
    ll ans=0;
    n++;
    for(int i=2; i<=sqrt(n); i++){
        ll res=0;
        ll anterior=1;
        while(res<=n){
            res= anterior*i;
            ans++;
            if(res>n) continue;
            a[res].push_back(i);
            anterior=res;
        }
    }
    n--;

    map<ll, ll> facts;
    buscarPrimos();
    fact(n, facts);

    vector<ll> anss;
    for(auto i : facts){
        ll pow = i.first;
        forn(j, i.second){
            //cout << pow << endl;
            anss.push_back((n / pow) - 1);
            pow *= i.first;
        }
    }
    
    for(int i=0; i<a[n+1].size();i++){
        anss.push_back(a[n+1][i]);
    }
    anss.push_back(n-1);
    sort(anss.begin(),anss.end());
    ll anterior=0;

    if(n==2){
      cout << "*" << endl;
      return 0;
    }

    if(anss.size()==0){
      cout << "*" << endl;
      return 0;
    }

    forn(j,anss.size()){
      if(anss[j]<=1) continue;
      if(anss[j]==anterior) continue;
      cout << anss[j] << " ";
      anterior=anss[j];
    }
    cout << endl;
    
    return 0;
}