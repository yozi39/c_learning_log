#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD=1e3,M=110,K=150,N=1010;

LL k,x,n;
int f[M][K];

void ADD(int c[],int b[]){
    for(int i=0;i<K-1;i++){
        c[i]+=b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}

LL qpow(LL a,LL b){
    a%=MOD;
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%MOD;
        b>>=1;
        a=a*a%MOD;//有可能溢出
    }
    return ret;
}

int main(){
    cin>>k>>x;
    n=qpow(x,x);//防止溢出

    for(int i=0;i<n;i++){
        f[0][0]=1;
        for(int j=min(1ll*i,k);j>=1;j--){
            ADD(f[j],f[j-1]);
        }
    }

    int p = K-1;
    while(f[k-1][p]==0){
        p--;
    }
    while(p>=0){
        cout<<f[k-1][p--];
    }
}