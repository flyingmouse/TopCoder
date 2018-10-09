#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

struct Point {
    int x, y, len;
    Point(int x, int y, int len): x(x), y(y), len(len) {}
};

class FindThePerfectTriangle {
    public:
    vector <int> constructTriangle(int area, int perimeter) {
        int x, r, n = 3000;
        vector<Point> points;
        REP(i, n) REP(j, n) {
            x = i * i + j * j;
            if (x * 4 >= perimeter * perimeter) break;
            r = (int) sqrt(x);
            if (r * r == x) {
                points.push_back(Point(i, j, r));
            }
        }
        n = points.size();
        REP(i, n) REPP(j, i + 1, n) {
            Point a = points[i], b = points[j];
            x = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
            r = (int) sqrt(x);
            if (r * r == x && a.len + b.len + r == perimeter) {
                if (abs(a.x * b.y - a.y * b.x) == 2 * area) {
                    return {0, 0, a.x, a.y, b.x, b.y};
                }
            }
        }
        return {};
    }
};
