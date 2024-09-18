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

int suscesor = 1;
int last_index = 0;

typedef struct Nodo {
    vector<int> childs;
    bool dead;
    bool visitado;
} Nodo;

vector<Nodo> tree;

void insert(int x){
    tree[x].childs.push_back(last_index+1);
    tree.push_back(Nodo{});
    last_index ++;
}

void kill(int x){
    tree[x].dead = true;
}

/*

ahora SI*/

int next_sucesor(int x){
    bool deadChilds = true;
    for(int i : tree[x].childs){
        if (tree[i].visitado){
            continue;
        }
        deadChilds &= tree[i].dead;
        if (!tree[i].dead){
            return i;
        }
        int child = next_sucesor(i);
        if (child != -1){
            return child;
        }
        tree[i].visitado = deadChilds & tree[i].dead;
    }
    return -1;
}

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> q;
    tree.push_back(Nodo{});
    insert(0);

    while(q--){
        int t, x;
        cin >> t >> x;

        if (t == 1){
            insert(x);

        }else{
            kill(x);

            if (x == suscesor){
                int next = next_sucesor(0);
                if (next != -1){
                    suscesor = next;
                }
            }
            cout << suscesor << endl;
        }
    }

    return 0;
}