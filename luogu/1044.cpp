#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int main(){
    LL n;cin>>n;
    LL f[n];
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=0;
        for(int j=0;j<i;j++){
            f[i]=f[i]+f[j]*f[i-j-1];
        }
    }
    cout<<f[n];
}