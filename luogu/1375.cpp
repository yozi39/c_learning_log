#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N=2e5+10,MOD=1e9+7;

LL n;
LL fac[N],invfac[N];

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
    fac[0]=1;
    for(int i=1;i<=2*n;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    invfac[2*n]=qpow(fac[2*n],MOD-2);
    for(int i=2*n-1;i>=0;i--){
        invfac[i]=invfac[i+1]*(i+1)%MOD;
    }
}

LL C(LL n,LL m){
    if(n<m)return 0;
    return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}

int main(){
    cin>>n;
    init();

    cout<<((C(2*n,n)-C(2*n,n-1))%MOD+MOD)%MOD;
}