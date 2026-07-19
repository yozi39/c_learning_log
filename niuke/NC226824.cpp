#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> inv;
LL p,n;

LL exgcd(LL a,LL b,LL& x,LL& y){
    if(b==0){
        x=1;y=0;
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
        LL x,y;
        cin>>n>>p;
        LL d = exgcd(n,p,x,y);
        if(d!=1)cout<<-1<<endl;
        else{
            cout<<(x%p+p)%p<<endl;
        }
    }
}