#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int n;
LL f[25];

int main(){
    cin>>n;
    f[1]=0;
    f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
    cout<<f[n];
}