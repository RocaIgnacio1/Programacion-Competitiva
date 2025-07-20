    #include <bits/stdc++.h>
    #define forr(i, a, b) for (int i = (a); i < (b); i++)
    #define forn(i, n) forr(i, 0, n)
    #define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
    #define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
    #define pb push_back
    #define ll long long
     
    using namespace std;
     
    vector<ll> divisors(ll n){
        vector<ll> v;
        for(ll i = 1; i * i <= n; i++){
            if(n%i == 0){
                if(i*i != n){
                    v.push_back(n/i);
                }
                v.push_back(i);
            }
        }
        return v;
    }
     
    ll ans(ll n){
        vector<ll> divs = divisors(n);
        sort(divs.begin(), divs.end());
        // for(auto d : divs) cout << d << ' '; cout << endl;
        set<pair<ll, ll>> s;
        for(int i = 0; i < divs.size(); i++){
            for(int j = i; j < divs.size(); j++){
                ll p = divs[i];
                ll q = divs[j];
                ll d = __gcd(p, q);

                // cout << p / d << "/" << q / d << ' ' << p % q << endl;
                if (s.find({p/d, q/d}) == s.end()){
                    //cout << p  << "/" << q  << endl;
                    // cout << "YES\n";
                    s.insert({p/d, q/d});
                }
            }
        }
        //cout << "teta: " << teta << endl;
        //cout << "dists: " << dists << endl;
        return s.size();
    }
     
    int main() {
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
        int q;
        cin >> q;
        map<ll,int> nums;
        forn(i, q){
            ll n; cin >> n;
            if(nums.find(n)!=nums.end())cout << nums[n] << endl;
            else{
            nums[n]=ans(n);
            cout <<  nums[n] << endl;
        }
        }
     
        return 0;
    }