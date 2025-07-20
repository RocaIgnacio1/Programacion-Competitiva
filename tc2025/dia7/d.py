import sys
import math

input = sys.stdin.readline

class Vec3:
    def __init__(self, x,y,z):
        self.x = x; self.y = y; self.z = z
    def __sub__(self, other):
        return Vec3(self.x - other.x, self.y - other.y, self.z - other.z)
    def cross(self, other):
        return Vec3(self.y*other.z - self.z*other.y,
                    self.z*other.x - self.x*other.z,
                    self.x*other.y - self.y*other.x)
    def norm(self):
        return math.sqrt(self.x*self.x + self.y*self.y + self.z*self.z)

def triangle_area(a,b,c):
    return 0.5 * ((b - a).cross(c - a)).norm()

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.r = [0]*n
        self.area = [0.0]*n
    def find(self, x):
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x
    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return u
        if self.r[u] < self.r[v]:
            u, v = v, u
        self.p[v] = u
        self.area[u] += self.area[v]
        if self.r[u] == self.r[v]:
            self.r[u] += 1
        return u

n = int(input())
points = []
for _ in range(n):
    x,y,z = map(int, input().split())
    points.append(Vec3(x,y,z))

m = int(input())
faces = []
for _ in range(m):
    a,b,c = map(int, input().split())
    faces.append((a-1,b-1,c-1))

face_infos = []
for (a,b,c) in faces:
    area = triangle_area(points[a], points[b], points[c])
    zmin = min(points[a].z, points[b].z, points[c].z)
    face_infos.append((zmin, area, a, b, c))

q = int(input())
queries = []
for i in range(q):
    h,p = map(int, input().split())
    queries.append((h, p-1, i))

events = []
for zmin, area, a,b,c in face_infos:
    events.append((zmin, 0, (area,a,b,c)))
for h,p,i in queries:
    events.append((h, 1, (p,i)))

events.sort(key=lambda x: (x[0], x[1]))

dsu = DSU(n)
res = [-1.0]*q

for height, typ, data in events:
    if typ == 0:
        area, a,b,c = data
        if points[a].z > height and points[b].z > height and points[c].z > height:
            dsu.union(a,b)
            dsu.union(b,c)
            root = dsu.find(a)
            dsu.area[root] += area
    else:
        p,i = data
        if points[p].z <= height:
            res[i] = -1.0
        else:
            root = dsu.find(p)
            res[i] = dsu.area[root]

for val in res:
    if val == -1:
        print(-1)
    else:
        print(f"{val:.9f}")
