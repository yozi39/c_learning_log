#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL qpow(LL a, LL b, LL mod) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }

        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    LL n, m, k, x;
    cin >> n >> m >> k >> x;

    LL rounds = qpow(10, k, n);
    cout << (x + m * rounds) % n;
}