#include<bits/stdc++.h>
using namespace std;
using LL = long long;
//正难则反
const int MOD=100003;

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
    LL n,m;cin>>m>>n;
    cout<<((qpow(m,n)-m*qpow(m-1,n-1)%MOD)%MOD+MOD)%MOD;
}