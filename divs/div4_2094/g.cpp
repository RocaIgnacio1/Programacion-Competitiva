#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)

using namespace std;

typedef unsigned long long ll;

struct Array {
    ll rizz = 0;
    ll rev_rizz = 0; // rizz function in reverse order
    ll sum = 0;
    ll n = 0;
    bool order;

    deque<ll> elements;
    int back() {
        return order ? elements.back() : elements.front();
    }
    void push_back(ll k) {
        order ? elements.push_back(k) : elements.push_front(k);
    }
    void push_front(ll k) {
        order ? elements.push_front(k) : elements.push_back(k);
    }
    void pop_back() {
        order ? elements.pop_back() : elements.pop_front();
    }

    void append(ll k) {
        rev_rizz += sum + k;
        n += 1;
        rizz += n*k;
        sum += k;

        push_back(k);
    }

    void shift() {
        rizz += sum - n*back();
        rev_rizz += -1*sum + n*back();

        // elements shift
        ll last = back(); pop_back();
        push_front(last);
    }

    void reverse() {
        swap(rizz, rev_rizz);
        order = !order;
    }
};

void solve() {
    int q; cin >> q;
    Array a = Array{};

    while(q--){
        int op; cin >> op;
        switch (op) {
            case 1:
                a.shift();
                break;
            case 2:
                a.reverse();
                break;
            case 3:
                int k; cin >> k;
                a.append(k);
                break;
        }
        cout << a.rizz << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
