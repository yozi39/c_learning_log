#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL n,m;

LL gcd(LL a,LL b){
    return b==0? a:gcd(b,a%b);
}

int main(){
    cin>>n>>m;
    n++;m++;
    LL t=n*m;
    LL ret=t*(t-1)*(t-2)/6-m*n*(n-1)*(n-2)/6-n*m*(m-1)*(m-2)/6;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            ret-=2*(n-j)*(m-i)*((gcd(i,j)-1));
        }
    }
    cout<<ret;
}