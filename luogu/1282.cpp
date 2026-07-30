#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1005,M=1e4+10,INF=0x3f3f3f3f;

int n,ret,bret;
LL S1,S2,best;
int a[3][N],f[N][M];

void dfs(int x){
    if(x>n){
        LL diff=abs(S1-S2);

        if(diff<best || (diff==best && ret<bret)){
            best=diff;
            bret=ret;
        }

        return;
    }

    dfs(x+1);

    ret++;
    S1+=a[2][x]-a[1][x];
    S2+=a[1][x]-a[2][x];

    dfs(x+1);

    ret--;
    S1-=a[2][x]-a[1][x];
    S2-=a[1][x]-a[2][x];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[1][i]>>a[2][i];
        a[0][i]=a[1][i]-a[2][i];
        S1+=a[1][i];
        S2+=a[2][i];
    }

    int m=5000;
    memset(f,0x3f,sizeof f);
    f[0][0+m]=0;

    for(int i=1;i<=n;i++){
        for(int j=-m;j<=m;j++){
            f[i][j+m]=min(f[i-1][j-a[0][i]+m],f[i-1][j+a[0][i]+m]+1);
        }
    }

    int ret=INF;
    for(int i=0;i<=m;i++){
        ret=min(f[n][m+i],f[n][m-i]);
        if(ret!=INF){
            break;
        }
    }
    cout<<ret;
    // best=abs(S1-S2);
    // dfs(1);
    // cout<<bret;
}