#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10,MOD=5000011;

LL f[N],g[N];
LL n,k;

LL qpow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}

void init(){
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%MOD;
    }
    g[n]=qpow(f[n],MOD-2);
    for(int i=n-1;i>=0;i--){
        g[i]=g[i+1]*(i+1)%MOD;
    }
}

LL C(LL n,LL m){
    if(n<m)return 0;
    if(m==0)return 1;
    return f[n]*g[n-m]%MOD*g[m]%MOD;
}

int main(){
    cin>>n>>k;
    init();
    LL ans=0;
    for(int i=0;i<=n;i++){
        ans =(ans+C(n-(i-1)*k,i))%MOD;
    }
    cout<<ans;
}