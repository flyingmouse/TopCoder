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
    ll x, y;
    Point(int x, int y): x(x), y(y) {}

    bool operator == (const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class CheckPolygon {
    public:
    bool parallel(Point& p1, Point& p2, Point& p3) {
        return (p2.y - p1.y) * (p3.x - p2.x) == (p2.x - p1.x) * (p3.y - p2.y);
    }

    int orientation(Point& p1, Point& p2, Point& p3) {
        ll d = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
        if (d == 0) return 0;
        return d > 0 ? 1 : -1;
    }

    int online(Point& p1, Point& p2, Point& p) {
        return p.x >= min(p1.x, p2.x) && p.x <= max(p1.x, p2.x) && p.y >= min(p1.y, p2.y) && p.y <= max(p1.y, p2.y);
    }

    bool cross(Point& p1, Point& p2, Point& p3, Point& p4) {
        int a = orientation(p1, p2, p3), b = orientation(p1, p2, p4);
        int c = orientation(p3, p4, p1), d = orientation(p3, p4, p2);

        if (a != b && c != d) return true;
        if (a == 0 && online(p1, p2, p3)) return true;
        if (b == 0 && online(p1, p2, p4)) return true;
        if (c == 0 && online(p3, p4, p1)) return true;
        if (d == 0 && online(p3, p4, p2)) return true;
        return false;
    }

    string check(vector <int> x, vector <int> y) {
        int n = x.size();
        vector<Point> points;
        REP(i, n) points.push_back(Point(x[i], y[i]));
        points.push_back(Point(x[0], y[0]));
        REP(i, n) if (points[i] == points[i + 1]) return "Not simple";
        REP(i, n - 1) if (parallel(points[i], points[i + 1], points[i + 2])) return "Not simple";
        REP(i, n) REP(j, n) if (abs(i - j) > 1 && abs(i - j) < n - 1) {
            if (cross(points[i], points[i + 1], points[j], points[j + 1])) {
                return "Not simple";
            }
        }
        ll area = 0;
        REP(i, n) area += points[i].x * points[i + 1].y - points[i + 1].x * points[i].y;
        area = abs(area);
        char ans[30];
        sprintf(ans, "%lld.%d", area / 2, (area & 1) ? 5 : 0);
        return string(ans);
    }
};