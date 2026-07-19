#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MOD=998244353,N=1e9+5;

LL qpow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    LL n,k;
    cin>>n>>k;
    cout<<qpow(qpow(2,k)-1,n);
}