#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=405,MOD=1e9+7;

LL a[N][2*N];
int n;

LL qpow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ret;
}

int gauss(){
    for(int i=1;i<=n;i++){
        LL aim=i;
        for(int j=1;j<=n;j++){
            if(j<i && a[j][j]){
                continue;
            }
            if(abs(a[j][i])>abs(a[aim][i]))aim=j;
        }

        if(!a[aim][i])return 0;

        for(int j=1;j<=2*n;j++)swap(a[aim][j],a[i][j]);
        LL t=qpow(a[i][i],MOD-2);
        for(int j=i;j<=2*n;j++){
            a[i][j]=a[i][j]*t%MOD;
        }

        for(int j=1;j<=n;j++){
            if(i==j)continue;
            LL t=a[j][i];
            for(int k=i;k<=2*n;k++){
                a[j][k]-=a[i][k]*t;
                a[j][k]=(a[j][k]%MOD+MOD)%MOD;
            }
        }
    }

    return 1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=n+1;i<=2*n;i++)a[i-n][i]=1;

    int ret = gauss();
    if(ret==0)cout<<"No Solution"<<'\n';
    else{
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<=n+n;j++){
                cout<<a[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}