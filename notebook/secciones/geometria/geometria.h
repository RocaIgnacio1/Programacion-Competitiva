typedef long long ll;
typedef long long ld;

struct pto {
    ll x, y;
    pto operator+(pto b);
    pto operator-(pto b); 
    pto operator+(ll k);
    pto operator*(ll k);
    pto operator/(ll k);
    ll operator*(pto b);
    pto proj(pto b);
    ll operator^(pto b);
    ld norm();
    ld dist(pto b);
};
