#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=500010;
int k,pos,ans;
LL a[N];

int main(){//先判断win or lose
    cin>>k;
    int ret=0;
    for(int i=1;i<=k;i++){
        LL tmp;cin>>tmp;
        a[i]=tmp;
        ret^=tmp;
    }

    if(ret==0){
        cout<<"lose";
        return 0;
    }
    else{
        for(int i=1;i<=k;i++){
            if((a[i]^ret)<a[i]){
                cout<<a[i]-(a[i]^ret)<<' '<<i<<'\n';
                a[i]^=ret;
                break;
            }
        }
        for(int i=1;i<=k;i++)cout<<a[i]<<' ';
    }
}