#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int n;
struct Point {
    int r, theta;
};
bool ord(const Point &a, const Point &b){
    return a.r < b.r;
}

struct Line {
    int r1, r2, theta;
};
vector<Line> lines;
vector<Point> points;

bool is_path(const Point &a, const Point &b){
    int min_theta = min(a.theta, b.theta);
    int max_theta = max(a.theta, b.theta);
    cout << "|" << a.theta << ", " << b.theta << endl;
    cout << "min:" << min_theta << endl;
    cout << "max:" << max_theta << endl;

    bool alpha = false, betha = false;
    for (Line line : lines) {
        cout << "line:" << line.r1 << ", " << line.r2 << endl;
        if (line.r1 <= a.r && line.r2 >= b.r){
            if (line.theta <= max_theta && line.theta >= min_theta) {
                cout << "alpha" << endl;
                alpha = true;
            }
            if (line.theta < min_theta || line.theta > max_theta) {
                cout << "betha" << endl;
                betha = true;
            }
        }
    }
    cout << "a: " << alpha << " b: " << betha << endl;

    return !(alpha && betha); // Si no tiene una linea q corta de los dos lados, se puede
}

bool dfs(int start){
    // Si estamos en el anillo exterior
    cerr << "dfs(" << start << ")" << endl;
    cerr << points[start].r << " < " << points[start].theta << endl;
    if (points[start].r == points[points.size()-1].r) return true;
    bool path = false;
    int next_ring = -1;

    for(int i = start; i < points.size(); i++){
        // Saltamos los q estan en el mismo anillo
        if (points[start].r == points[i].r) continue;
        if (next_ring != -1 && points[i].r != next_ring) break;

        cout << "is_path(" << start << "," << i << ") = ";
        if (is_path(points[start], points[i])){
            cout << "true" << endl;
            path |= dfs(i);
            cout << "dfs: " << start << "=" << next_ring << endl;
        }else{
            cout << "false" << endl;
        }
        if (next_ring == -1) next_ring = points[i].r;
        if (path) return path;
    }

    return path;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        cin >> n;
        points.clear();
        lines.clear();

        points.push_back(Point{0, 0});
        forn(i, n){
            char l;
            int a, b, c;
            cin >> l >> a >> b >> c;
            if (l == 'C') {
                points.push_back(Point{a, b});
                points.push_back(Point{a, c});
            } else {
                lines.push_back(Line{a, b, c});
            }
        }

        sort(points.begin(), points.end(), ord);
        for(auto p : points){
            cerr << p.r << " < " << p.theta << endl;
        }

        /*cerr << "path: " << is_path(points[4], points[5]) << endl;*/

        if (dfs(0)) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
