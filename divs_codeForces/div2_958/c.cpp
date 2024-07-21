#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i >= 0; i--)
#include <math.h>


int main() {
   
    int x=14;
    int t=1;
    vector<ll> v;
    while (t < x) {
		if (x & t) {
			v.push_back(x - t);
		}
		t <<= 1;
	}
    for(int i=0; i<v.size();i++){
        cout << " " << v[i];
    }
    return 0;
}