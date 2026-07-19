#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL& x,LL& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    LL x1,y1;
    LL d=exgcd(b,a%b,x1,y1);
    x=y1;y=x1-a/b*y1;
    return d;

}

int main(){
    int T;cin>>T;
    while(T--){
        LL a,b,d,x,y;cin>>a>>b;
        d=exgcd(a,b,x,y);
        if(d==1){
            LL k1,k2;k1=b;k2=a;
            cout<<(x%k1+k1)%k1<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
}