#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m,l,MOD;

void print(LL x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

LL qpow(LL time,LL x){
    LL ret=1,a=n/2+1;
    while(time){
        if(time&1)ret=(__int128)ret*a%MOD;
        time>>=1;
        a=(__int128)a*a%MOD;
    }
    return (__int128)ret*x%MOD;
}

int main(){
    cin>>n>>m>>l;
    MOD=(n+1);

    print(qpow(m,l));
}