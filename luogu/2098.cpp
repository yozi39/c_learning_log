#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL N=1010,MOD=1000000009;

int n,m,p;
int a[N],b[N];
int f[N][N][11];

int main(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j][0]=1;
        }
    }

    for(int k=1;k<=p;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j][k] = (f[i][j-1][k]+f[i-1][j][k])%MOD-f[i-1][j-1][k];
                f[i][j][k] = (f[i][j][k]%MOD+MOD)%MOD;

                if(a[i]>b[j])f[i][j][k] = (f[i][j][k]+f[i-1][j-1][k-1])%MOD;
            }
        }
    }

    cout<<f[n][m][p];
}