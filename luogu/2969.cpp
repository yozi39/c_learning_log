#include <bits/stdc++.h>
using namespace std;

const int N = 50005;

int n, q;
int sum[N];

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        sum[i] = sum[i - 1] + b;
    }

    while (q--) {
        int T;
        cin >> T;

        int pos = upper_bound(sum + 1, sum + n + 1, T) - sum;
        cout << pos << '\n';
    }
}