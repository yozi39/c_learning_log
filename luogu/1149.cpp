#include <bits/stdc++.h>
using namespace std;

int n;

int matchCount[10] = {
    6, 2, 5, 5, 4,
    5, 6, 3, 7, 6
};

int cost(int x) {
    if (x == 0) {
        return matchCount[0];
    }

    int res = 0;

    while (x > 0) {
        res += matchCount[x % 10];
        x /= 10;
    }

    return res;
}

int main() {
    cin >> n;

    int ans = 0;

    n -= 4;

    for (int a = 0; a <= 999; a++) {
        for (int b = 0; b <= 999; b++) {
            int c = a + b;

            if (cost(a) + cost(b) + cost(c) == n) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}