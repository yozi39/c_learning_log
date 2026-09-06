#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e3+5;

int n,m;
LL a[N][N],f[N][N];
LL down[N],up[N];

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        f[i][1]=f[i-1][1]+a[i][1];
    }

    for(int j=2;j<=m;j++){
        down[1]=f[1][j-1]+a[1][j];
        for(int i=2;i<=n;i++){
            down[i]=max(f[i][j-1],down[i-1])+a[i][j];
        }

        up[n]=f[n][j-1]+a[n][j];
        for(int i=n-1;i>=1;i--){
            up[i]=max(f[i][j-1],up[i+1])+a[i][j];
        }

        for(int i=1;i<=n;i++){
            f[i][j]=max(down[i],up[i]);
        }
    }

    cout<<f[n][m];
}