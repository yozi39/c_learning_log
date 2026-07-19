#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+10,MOD=1e9+7;
LL n,m,k;
int cnt[N];
LL fac[N],invfac[N];
LL f[N];

LL C(LL n,LL m){
    if(n<m)return 0;
    return fac[n]*invfac[n-m]%MOD*invfac[m]%MOD;
}

LL qpow(LL a,LL b){
    LL ret=1;
    while (b)
    {
        if(b&1)ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=i*fac[i-1]%MOD;
    invfac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%MOD;
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
    }

    init();

    for(int i=m;i>=1;i--){
        LL x=0;

        for(int j=i;j<=m;j+=i){
            x+=cnt[j];
        }

        f[i]=C(x,k);

        for(int j=2*i;j<=m;j+=i){
            f[i]=(f[i]-f[j]+MOD)%MOD;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<' ';
    }
}