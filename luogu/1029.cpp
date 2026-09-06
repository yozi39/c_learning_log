#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long x,y;

LL gcd(LL a,LL b){
    return b==0? a:gcd(b,a%b);
}

int main(){
    cin>>x>>y;

    LL cnt=0;
    for(LL i=1;i<=100000;i++){
        long long j=1ll*x*y/i;
        if(x*y%i)continue;
        if(gcd(i,j)==x)cnt++;
    }
    cout<<cnt;
}