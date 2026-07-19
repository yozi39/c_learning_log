#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int MOD=1e9+7,N=1e6+5,K=5565709+5;

LL f[N];
LL ff[N],gg[N];

LL qpow(LL a,LL b){
    LL ret=1;
    while (b)
    {
        if(b&1)ret=ret*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ret;
}

void init(){
    ff[0]=1;
    for(int i=1;i<=N-5;i++){
        ff[i]=ff[i-1]*i%MOD;
    }
    gg[N-5]=qpow(ff[N-5],MOD-2);
    for(int i=N-6;i>=0;i--){
        gg[i]=gg[i+1]*(i+1)%MOD;
    }
}

LL C(LL n,LL m){
    if(n<m){
        return 0;
    }
    if(n==m)return 1;
    return ff[n]%MOD*(gg[n-m]%MOD)%MOD*(gg[m]%MOD)%MOD;
}

int main(){
    int T;cin>>T;
    init();
    f[0]=1;
    f[2]=1;
    for(int i=3;i<=N-5;i++){
        f[i]=((f[i-1]%MOD+(f[i-2]%MOD)%MOD))*(i-1)%MOD;
    }
    while(T--){
        int n,m;cin>>n>>m;
        int num=n-m;
        
        cout<<(f[num]*C(n,m)%MOD)<<'\n';
    }
}