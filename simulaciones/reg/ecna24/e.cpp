        #include <bits/stdc++.h>
        #include <bitset>
        #include <iostream>
        #include <string>
        using namespace std;
        #define forn(i,n) for(int i = 0; i < n; i++)
        #define fora(p, i,n) for(int i = p; i < n; i++)
        #define pb push_back
        typedef long long ll;
        #define MAXN 1000000010
        #ifdef EBUG
        //local
        #else
        //judge
        #endif
        
        
        __int128_t pot = (__int128_t)1;
        string s;
        __int128_t MAXI = (__int128_t)1;
        
        __int128_t solve(int pos, __int128_t n){
            cout << (ll)n << " " << s[pos] <<  endl;
            __int128_t res;
            if(pos == s.size()){
                return n;
            }
            if(n%2 == 0){
                if((n-1)%3 == 0 && ((s[pos] == 'E' && ((n-1)/3) % 2 == 0) || (s[pos] == 'O' && ((n-1)/3) % 2 == 1))){
                    res = solve(pos+1, (n-1)/3);
                }else{
                    res = solve(pos+1, n*2);
                } 
            }else{
                if((n-1)%3 != 0 || ((s[pos] == 'E' && ((n-1)/3) % 2 != 0) || (s[pos] == 'O' && ((n-1)/3) % 2 != 1))) return -1;
                res = solve(pos+1, (n-1)/3);
            }
            return pot;
        }
        int main(){
            #ifdef EBUG
                freopen("input.txt", "r", stdin);
            #endif
            ios :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

            cin >> s;
            reverse(s.begin(), s.end());
            ll res;
            forn(i, 47){
                MAXI *= 2;
            }
            MAXI++;

            __int128_t m = MAXI;
            forn(i, 47){
                __int128_t x = (solve(0, pot));
                pot*=2;
                cout << (ll)x << endl;
                if(x>0) continue;
                MAXI = min(MAXI, x);
                res = (ll)MAXI;
            }

            if(MAXI < m) cout << res << endl;
            else cout << "INVALID" << endl;
        }