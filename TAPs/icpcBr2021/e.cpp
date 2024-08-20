#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    deque<int> b, s;
    forn(i, n){
        int A,B;
        cin >> A >> B;
        if(B == 0) b.push_back(A);
        if(B == 1) s.push_back(A);
    }
    sort(s.begin(), s.end());
    sort(b.begin(), b.end());

    int sum = 0;
    while(!b.empty() || !s.empty()){
        sum += 10;
        //cout << sum << endl;
        if(b.empty()){
            if(sum < s[s.size() - 1] + 10) sum = s[s.size() - 1] + 10;
            break;
        }
        if(s.empty()){
            if(sum < b[b.size() - 1] + 10) sum = b[b.size() - 1] + 10;
            break;
        }
        int aux = 0;
        if(s[0] < b[0]){
            if(sum < s[0] + 10) sum = s[0] + 10;
            s.pop_front();
            while((!s.empty() && s[0] <= sum)){
                if(sum < s[0] + 10) sum = s[0] + 10;
                s.pop_front();
            }
        }else{
            if(sum < b[0] + 10) sum = b[0] + 10;
            b.pop_front();
            while((!b.empty() && b[0] <= sum)){
                if(sum < b[0] + 10) sum = b[0] + 10;
                b.pop_front();
            }
        }
    }
    cout << sum << endl;
    return 0;
}