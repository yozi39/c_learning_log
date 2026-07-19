#include<bits/stdc++.h>
using namespace std;
//两个方法一个是利用卡特兰数方法四,或者新来一个方法5动态规划+空间优化
//因为两个高精度太麻烦,素=所以用方法5

const int N=510;
int n;
int f[N][N];

void ADD(int a[],int c[]){
    for(int i=0;i<N-1;i++){
        c[i]+=a[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}

int main(){
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){//不能越过对角线
            ADD(f[j-1],f[j]);
        }
    }
    int p=N-1;
    while(f[n][p]==0){
        p--;
    }
    while (p>=0)
    {
        cout<<f[n][p--];
    }
}