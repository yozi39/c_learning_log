#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int main(){
    LL n;
    while(cin>>n){
        LL ret=n/2+n/5+n/11+n/13-n/10-n/22-n/26-n/55-n/143-n/65+n/110+n/130+n/286+n/715-n/1430;
        ret=n-ret;
        cout<<ret<<'\n';
    }
}