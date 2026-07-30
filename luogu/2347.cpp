#include <bits/stdc++.h>
using namespace std;

int main(){
    int w[7] = {0, 1, 2, 3, 5, 10, 20};
    int a[7];

    for(int i = 1; i <= 6; i++){
        cin >> a[i];
    }

    int dp[1005]={};
    dp[0]=true;

    for(int i=1;i<=6;i++){
        for(int j=1000;j>=0;j--){
            for(int k=0;k<=a[i] && k*w[i] <=j;k++){
                dp[j] = dp[j] || dp[j-k*w[i]];
            }            
        }
    }

    int ret=0;

    for(int i=1;i<=1000;i++){
        if(dp[i]){
            ret++;
        }
    }

    cout<<"Total="<<ret;
}