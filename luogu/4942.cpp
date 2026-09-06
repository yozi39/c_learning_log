#include<bits/stdc++.h>
using namespace std;
typedef __int128 LL;

const int MOD=9;
LL add(long long x,long long y){
    return (LL)(x+y)*(y-x+1)/2;
}

int main(){
    int T;cin>>T;
    while (T--)
    {
        long long l,r;
        cin>>l>>r;
        LL sum = add(l,r);
        long long ret=sum%MOD;
        cout<<ret<<'\n';
    }
}