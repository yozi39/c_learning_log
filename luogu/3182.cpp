#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL n;
int f[205][405];

void ADD(int a[],int b[],int c[]){
    for(int i=0;i<=400;i++){
        c[i]+=b[i]+a[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}

void MUL(int c[],int a,int b[]){
    for(int i=0;i<=400;i++){
        c[i]+=a*b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}

int main(){
    int a;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a;
        }
    }

    f[2][0]=1;
    for(int i=3;i<=n;i++){
        int tmp[405]={0};
        ADD(f[i-1],f[i-2],tmp);
        MUL(f[i],(i-1),tmp);
    }
    
    int q=400;
    if(n == 1){
        cout<<0;
        return 0;
    }
    while(f[n][q]==0){
        q--;
    }
    while(q>=0){
        cout<<f[n][q--];
    }
}