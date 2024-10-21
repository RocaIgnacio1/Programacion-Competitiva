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

const int isbn10M = 11;
int checksum10(string s, int digits){
    int checksum = 0;
    for(char c : s){
        if (c != '-'){
            int d = c-'0';
            if (c == 'X') d = 10;
            assert(digits >= 1);
            checksum += digits * d;
            //cout << digits << "*" << c << " + ";
            digits--;
        }
    }
    return checksum % isbn10M;
}

string checksum13(string s){
    int checksum = 0;
    int cont = 0;
    forn(i, s.size()-1){
        char c = s[i];
        if (c == '-') continue;
        int d = c-'0';
        if (c == 'X') d = 10;
        if ((cont%2) == 0) {
            checksum += d;
            //cout << "1*" << d << " + ";
        }else{
            checksum += 3 * d;
            //cout << "3*" << d << " + ";
        }
        cont ++;
    }
    checksum %= 10;
    //cout << endl;
    int last_digit = 10 - checksum;
    //cout << last_digit << endl;
    s[s.size()-1] = (char)(last_digit+'0');
    return s;
}

string isbn10to13(string s){
    return checksum13("978-"+s);
}

bool validISBN10(string s){
    char prev = ' ';
    int pos = 0;
    int hyphens = 0;
    int last_h_pos = 0; //posicion ultimo - 
    for(char c : s){
        if (c == '-'){
            hyphens++;
            last_h_pos = pos;
            // No puede tener dos - seguidos. No puede empezar o terminar con -
            if (prev == '-' || pos == 0 || pos == s.size()-1){
                return false;
            }
        }
        pos ++;
    }
    if (hyphens > 3) return false; // no puede tener mas de 3 -
    // Si tiene 3 el ultimo - divide el checksum
    else if (hyphens == 3 && last_h_pos != s.size()-2) return false;
    //Validar el checksum
    int checksum = checksum10(s, 10);
    //cout << checksum << endl;
    if (checksum != 0) return false;

    return true;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;

    forn(i, t){
        string s;
        cin >> s;
        bool valid = validISBN10(s);
        if (valid){
            cout << isbn10to13(s) << '\n';
        }else{
            cout << "invalid\n";
        }
        //cout << "========================\n";
    }
    
    return 0;
}