#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

int calc(int num){
    if(num==1)return 0;
    int sum=1;

    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            sum+=i;
            if(i*i!=num)sum+=num/i;
        }
    }
    return sum;
}

int main() {
    HOLA;
    #ifdef EBUG
    freopen("d.txt", "r", stdin);
    #endif

    vector<int> a(200000);
    for(int i=1; i<200000; i++){
        a[i] = calc(i);
    }
    
    a[0]=0;
    int n;
    cin >> n;
    forn(i,n){
        int num;
        cin >> num;
        cout << num;
        if(num==1){
            cout << " complicado" << endl;
            continue;
        }

        if(a[num]==num){
            cout << " perfecto";
        }else{
            if(a[num]<100005 && a[a[num]]==num){
                cout << " romantico";
            }
            if(a[num]>num){
                cout << " abundante";
            }
        }
        
        if(a[num]<num && (a[num]>100005 || a[a[num]]!=num)){
            cout << " complicado";
        }
        cout << endl;
    }
    
    return 0;
}