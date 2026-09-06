#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL go(LL x, LL y) {
    if (x == 0 || y == 0) return 0;

    LL mn = min(x, y);
    LL mx = max(x, y);
    LL cnt = mx / mn;

    return 4LL * mn * cnt + go(mn, mx % mn);
}

int main() {
    LL x, y;
    cin >> x >> y;

    cout << go(x, y);
}