#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int main(){
    LL n;cin>>n;
    LL ret=1;
    for(int i=1;i<=n;i++){
        ret=ret*(4*i-2)/(i+1);
    }
    cout<<ret;
}