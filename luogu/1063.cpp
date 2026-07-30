#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=210;
int n;
LL ret;
int f[N][N],a[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }

    for(int len=3;len<=n+1;len++){
        for(int i=1;i+len-1<=n+n;i++){
            int j=i+len-1;
            for(int k=1+i;k<j;k++){
                //i,k  k,j
                f[i][j]=max(f[i][j],f[i][k]+f[k][j]+a[i]*a[j]*a[k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int j=i+n;
        ret=max(ret,1ll*f[i][j]);
    }

    cout<<ret;
}