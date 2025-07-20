#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define ll long long

using namespace std;

#define MAXP 100100 // no necesariamente primo
ll criba[MAXP + 1];
void crearcriba() {
    int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
    for (int p = 25; p <= MAXP; p += 10)
        criba[p] = 5;
    for (int p = 9; p <= MAXP; p += 6)
        criba[p] = 3;
    for (int p = 4; p <= MAXP; p += 2)
        criba[p] = 2;
    for (int p = 7, cur = 0; p * p <= MAXP; p += w[cur++ & 7])
        if (!criba[p])
            for (int j = p * p; j <= MAXP; j += (p << 1))
                if (!criba[j])
                    criba[j] = p;
}

vector<ll> primos;
void buscarprimos(){
    crearcriba();
    forr(i, 2, MAXP + 1) if (!criba[i]) primos.push_back(i);
}

vector<ll> factors(ll n) {
    vector<ll> f;
    for (auto x : primos) {
        if (x*x > n) break;
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

vector<ll> get_divisors_from_factors(vector<ll> &factors) {
    map<ll, int> factor_count;
    for (ll f : factors) factor_count[f]++;

    vector<ll> divisors = {1};
    for (auto fc : factor_count) {
        ll p = fc.first;
        ll exp = fc.second;
        vector<ll> new_divisors;
        for (ll d : divisors) {
            ll curr = 1;
            for (int i = 0; i <= exp; i++) {
                new_divisors.push_back(d * curr);
                curr *= p;
            }
        }
        divisors = move(new_divisors);
    }
    //cout << " divs: "; for(auto f : divisors) cout << f << ' '; cout << endl;
    //sort(divisors.begin(), divisors.end());
    return divisors;
}

ll ans(ll n) {
    vector<ll> facts = factors(n);
    vector<ll> divs = get_divisors_from_factors(facts);
    //sort(divs.begin(), divs.end());
    //cout << n << " facts: "; for(auto f : facts) cout << f << ' '; cout << endl;
    //cout << n << " divs: "; for(auto f : divs) cout << f << ' '; cout << endl;
    //cout << divs.size() << endl;
    ll dists = 0;
    for (int i = 0; i < divs.size(); i++) {
        for (int j = i; j < divs.size(); j++) {
            ll p = divs[i];
            ll q = divs[j];
            if (__gcd(p, q) == 1){ //coprimo
                //cout << p << "/" << q << endl;
                dists++;
            }
        }
    }
    // cout << "teta: " << teta << endl;
    // cout << "dists: " << dists << endl;
    return dists;
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int q;
    cin >> q;
    buscarprimos();
    map<ll,int> nums;
    forn(i, q) {
        ll n;
        cin >> n;
        if(nums.find(n)!=nums.end())cout << nums[n] << endl;
        else{
            nums[n]=ans(n);
            cout <<  nums[n] << endl;
        }
        // vector<int> facts = find_divisors(n);
        // for(auto f : facts) cout << f << ' '; cout << endl;
    }

    return 0;
}