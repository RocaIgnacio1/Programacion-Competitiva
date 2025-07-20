#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    #ifdef EBUG
    //freopen("input.txt", "r", stdin);
    #endif
    indexed_set<int> s;

    s.insert(5);
    s.insert(1);
    s.insert(10);
    s.insert(3);

    // Elementos ordenados: [1, 3, 5, 10]

    cout << *s.find_by_order(0) << "\n"; // 1
    cout << *s.find_by_order(2) << "\n"; // 5

    cout << s.order_of_key(5) << "\n";   // 2 (hay dos menores que 5)
    cout << s.order_of_key(6) << "\n";   // 3 (1,3,5 < 6)
    s.insert(8);
     cout << *s.find_by_order(4) << "\n";
    s.erase(3);
    cout << s.order_of_key(5) << "\n";   // 1 (quedaron 1 y 5 y 10)
}
