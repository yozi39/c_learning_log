#include<bits/stdc++.h>
using namespace std;

const int N=3005;

int n;
int a[N];
int f[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(a[i]==a[j]) f[i][j]=f[i+1][j-1];
            else f[i][j]=min(min(f[i][j-1],f[i+1][j]),f[i+1][j-1])+1;
        }
    }

    cout<<f[1][n];
}