#include<bits/stdc++.h>
using namespace std;
using LL =long long;
const int N=30,MOD=1e9+7;

LL n,s;
LL f[N];
LL inv;

LL C(LL n,LL m){
    if(n<m || n<0)return 0;
    LL up=1;
    for(LL i=n-m+1;i<=n;i++)up=up*(i%MOD)%MOD;
    return up*inv%MOD;
}

LL qpow(LL a,LL b){
    LL ret=1;
    a%=MOD;
    while (b)   
    {
        if(b&1)ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}

int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++)cin>>f[i];
    LL down=1;
    for(int i=1;i<n;i++){
        down=down*i;
    }
    inv=qpow(down,MOD-2);

    LL ret=0;
    for(int st=0;st<(1<<n);st++){
        LL cnt=0,sum=0;
        for(int i=0;i<n;i++){
            if((st>>i)&1){
                cnt++;
                sum+=f[i]+1;
            }
        }
        if(cnt%2==0)ret+=C(n+s-1-sum,n-1);
        else ret-=C(n+s-1-sum,n-1);
        ret=(ret%MOD+MOD)%MOD;
    }
    cout<<ret;
}