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
#include <unordered_map>
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PI 3.14159265359

typedef long long ll;
typedef pair<int, int> pii;

class FlightDataRecorder {
    public:
    double getDistance(vector <int> heading, vector <int> distance) {
        int n = heading.size();
        double x = 0, y = 0;
        REP(i, n) {
            double deg = (90 - heading[i]) * PI / 180;
            x += distance[i] * cos(deg);
            y += distance[i] * sin(deg);
        }
        double ans = sqrt(x * x + y * y);
        return ans;
    }
};
