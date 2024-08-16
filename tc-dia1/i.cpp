#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

bool mult3(string *s){
    int sum = 0;
    for(char c: *s){
        sum += c-'0';
    }
    return sum % 3 == 0;
}

bool mult4(string *s){
    vector<int> counts(10, 0); 
    for(char c: *s){
        int d = c-'0';
        counts[d] ++;
    }
    
    return counts[0] > 0 && (counts[2] > 0 || counts[4] > 0 || counts[6] > 0 || counts[8] > 0);
}

int main(){
    int n;
    cin >> n;

    forn(i, n){
        string y;
        cin >> y;

        bool is_zero = true;
        for(char c: y){
            if (c != '0'){
                is_zero = false;
                break;
            }
        }

        if ((mult3(&y) && mult4(&y)) || is_zero){
            cout << "red" << endl;
        }else{
            cout << "cyan" << endl;
        }
    }

    return 0;
}
