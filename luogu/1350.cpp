#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD=1e5+3,N=2e3+5;

LL a,b,c,d,k;
LL f[N],g[N];

LL qpow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ret;
}

void init(){
    f[0]=1;
    for(int i=1;i<=N-1;i++){
        f[i]=f[i-1]*i%MOD;
    }
    g[N-1]=qpow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;i--){
        g[i]=g[i+1]*(i+1)%MOD;
    }
}

LL C(LL n,LL m){
    if(m>n || m<0)return 0;
    return f[n]*g[n-m]%MOD*g[m]%MOD;
}

int main(){
    LL ans=0;
    cin>>a>>b>>c>>d>>k;
    init();
    for(int i=0;i<=k;i++){
        ans = (ans+(C(d,i)*C(c,i)%MOD*f[i]%MOD*C(b+d-i,k-i)%MOD*C(a,k-i)%MOD*f[k-i])%MOD)%MOD;
    }
    cout<<ans;
}