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
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;

struct matrix {
    int n, m;
    vector<vector<int> > ele;
    matrix(int n, int m):n(n), m(m) {
        ele.resize(n);
        REP(i, n) {
            ele[i].resize(m);
            REP(j, m) ele[i][j] = 0;
        }
    }

    void operator = (const matrix& u) {
        matrix(u.n, u.m);
        REP(i, n) REP(j, m) ele[i][j] = u.ele[i][j];
    }
};

matrix operator * (matrix u, matrix v) {
    int n = u.n, m = u.m;
    matrix c = matrix(n, m);
    REP(i, n) REP(j, m) REP(k, m)
        c.ele[i][j] = (c.ele[i][j] + 1LL * u.ele[i][k] * v.ele[k][j]) % MOD;
    return c;
}

matrix mat_pow(matrix u, int n) {
    if (n == 1) return u;
    if (n == 0) {
        matrix c = matrix(u.n, u.m);
        REP(i, u.n) c.ele[i][i] = 1;
        return c;
    }
    matrix c = mat_pow(u, n >> 1);
    c = c * c;
    if (n & 1) c = c * u;
    return c;
}

class ModEquationEasy {
    public:
    int count(int n, int K, int v) {
        matrix a = matrix(1, K);
        REP(i, K) a.ele[0][i] = 1;
        matrix p = matrix(K, K);
        REP(i, K) REP(j, K) p.ele[i][(i * j) % K]++;
        a = a * mat_pow(p, n - 1);
        return a.ele[0][v];
    }
};

