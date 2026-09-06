#include<bits/stdc++.h>
using namespace std;

const int N=3e4+5,M=30;

int n,m;
int v[M],p[M];
int dp[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>p[i];
        int x;cin>>x;
        v[i]=x*p[i];
    }

    for(int i=1;i<=m;i++){
        for(int j=n;j>=p[i];j--){
            dp[j]=max(dp[j],dp[j-p[i]]+v[i]);
        }
    }
    cout<<dp[n];
}