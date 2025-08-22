#include "pto.cpp"
using namespace std;
#define pb push_back
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)

// returns convex hull of p in CCW order
// left must return >=0 to delete collinear points
vector<pto> CH(vector<pto>& p) {
    if (p.size() < 3) return p;  // edge case, keep line or point
    vector<pto> ch;
    sort(p.begin(), p.end());
    forn(i, p.size()) {  // lower hull
        while (ch.size() >= 2 && ch[ch.size() - 1].left(ch[ch.size() - 2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    int k = ch.size();
    dforn(i, p.size()) {  // upper hull
        while (ch.size() >= k + 2 && ch[ch.size() - 1].left(ch[ch.size() - 2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    return ch;
}
