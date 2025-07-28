#include <bits/stdc++.h>
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

using namespace std;

typedef long long ll;

const int MAXN = 1e5+1;

struct Client {
    ll a, b;
    int pos; // original position
    int room = -1;

    bool operator<(Client c) {
        return a < c.a;
    }
};

bool operator<(ll a, Client c) {
    return a < c.a;
}

int main() {
    int n; cin >> n;
    vector<Client> clients(n);
    vector<int> ans(n);

    forn(i, n){
        ll a, b;
        cin >> a >> b;
        clients[i] = Client{a, b, i};
    }

    sort(all(clients));

    int last_room = 0;
    forn(i, n){
        auto it = upper_bound(all(clients), clients[i].b);
        if (it->a == clients[i].a) {
            it = next(it);
        }
        if (clients[i].room == -1) {
            clients[i].room = last_room++;
        }
        if (it != clients.end()){
            it->room = clients[i].room;
        }
        ans[clients[i].pos] = clients[i].room+1;
    }

    cout << endl;
    forn(i, n){
        cout << clients[i].a << ", " << clients[i].b << ": " << clients[i].room << endl;
    }
    cout << last_room << '\n';
    forn(i, n){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
