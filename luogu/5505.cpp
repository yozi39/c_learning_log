#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M=1005,N=2*M,MOD=1e9+7;

int n,m;
int a[N],c[N][N];

void init(){
    for(int i=0;i<=2000;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }

    init();
    LL ret=0;
    for(int i=0;i<n;i++){
        LL t=c[n][i];

        for(int j=1;j<=m;j++){
            t=t*c[n+a[j]-1-i][n-1-i]%MOD;
        }
        if(i&1)ret-=t;
        else ret+=t;
        ret=(ret%MOD+MOD)%MOD;
    }

    cout<<ret;
}