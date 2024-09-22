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

int suscesor = 0;
int last_index = 0;

typedef struct Nodo {
    int parent;
    vector<int> childs;
    bool dead;
} Nodo;

vector<Nodo> tree;

void insert(int x){
    tree[x].childs.push_back(last_index+1);
    tree.push_back(Nodo{.parent=x});
    last_index ++;
}

void kill(int x){
    tree[x].dead = false;
}

int next_sucesor(int x){
    for(int i : tree[x].childs){
        if (!tree[i].dead){
            return i;
        }
        next_sucesor(i);
    }
    return -1;
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int b, l;
    cin >> b >> l;
    vector<int> p, i, v;
    forn(j, l){
        int n;
        cin >> n;
        if(j % 2 == 0) p.push_back(n);
        if(j % 2 == 1) i.push_back(n);
        v.push_back(n);
    }
    int res = 0;
    for(auto j : p){
        res += j;
    }
    for(auto j : i){
        res -= j;
    }
    int mod = res % (b+1);
    int imp, par;
    if(res > 0){
        imp = b + 1 - mod;
        par = mod;
    }else{
        par = b + 1 + mod;
        imp = -mod;
    }
    //cout << imp << " " << par << endl;
    int min = 1e7;
    int posi = -1, posp = -1;
    int si1, si2, sp1, sp2;
    if(mod == 0){
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    forn(i, l){
        //cout << "i: " << i << " " << v[i] << " ";
        if(i % 2 == 0){
            //cout << par << endl;
            if(v[i] >= par){
                cout << i + 1 << " " << v[i] - par << endl;
                return 0;
            }
        }
        if(i % 2 == 1){
            //cout << imp << endl;
            if(v[i] >= imp){
                cout << i + 1 << " " << v[i] - imp << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}