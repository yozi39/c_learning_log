#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int n;
long long dp[N];

int sum(int x){
    return x * (x + 1) / 2;
}

int main(){
    cin >> n;

    int sumN = sum(n);

    if(sumN % 2 == 1){
        cout << 0;
        return 0;
    }

    int target = sumN / 2;

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = target; j >= i; j--){
            dp[j] += dp[j - i];
        }
    }

    cout << dp[target] / 2;
}