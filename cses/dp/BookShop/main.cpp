#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) begin(v), end(v)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1001;
const int MAXX = 1e5+1;

int n;
struct Book {
    int price;
    int pages;

    bool operator<(const Book &b) {
        return price < b.price;
    }
};
vector<Book> books;

// int solve(int i, int p) {
//     if (p <= 0) return dp[i][p] = 0;
//     if (i >= n) return 0;
//     if (dp[i][p] != -1) return dp[i][p];
//
//     cerr << books[i].pages << ' ' << p << endl;
//
//     int ans = solve(i+1, p); // no me llevo 
//     if (p-books[i].price >= 0) {
//         ans = max(ans, solve(i+1, p-books[i].price) + books[i].pages);
//     }
//     return dp[i][p] = ans;
// }

int main(){
    HOLA;
    int x; 
    cin >> n >> x;

    vector<int> h(n+1), s(n+1);
    forn(i, n) cin >> h[i];
    forn(i, n) cin >> s[i];

    forn(i, n){
        books.push_back(Book{h[i], s[i]});
    }
    sort(all(books));
    forn(i, n){
        cout << books[i].price << ' ';
    }
    cout << endl;

    vector<int> dp(x+1, 0);
    forn(i, x+1){
        forn(j, n) {
            if (i + books[j].price > x) continue;

            int ans = dp[i + books[j].price];
            dp[i + books[j].price] = max(ans, dp[i] + books[j].pages);
        }    
        forn(i, x+1){
            cout << i << ": " << dp[i] << ' ';
        }
        cout << endl;
    }

    int ans = -1;
    forn(i, x+1){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
 
    return 0;
}
