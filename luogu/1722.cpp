#include<bits/stdc++.h>
using namespace std;

const int N=205,MOD=100;//!!!100不是质数不能用费马小定理,导致前三个公式不能用,只能用四

int n;
int f[N];

int main(){
    cin>>n;
    
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            f[i]=(f[i]+f[j]*f[i-j-1]%MOD)%MOD;
        }
    }

    cout<<f[n];
}