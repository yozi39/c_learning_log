#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL a,b;

LL qmul(int a){
    if(a == 1) return 1;

    LL ret=1;
    for(int i=1;i<=b;i++){
        ret*=a;
        if(ret>1e9)return 0;
    }
    return ret;
}

int main(){
    cin>>a>>b;

    LL ret=qmul(a);
    
    if(ret){
        cout<<ret;
    }
    else{
        cout<<-1;
    }
}