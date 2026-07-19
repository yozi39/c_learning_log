#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//防溢出已经是它的一部分了QAQ
//能取模就取模,能龟速乘就龟速
const int N=1e5+10;

int n;
LL m[N],r[N];

LL qmul(LL x,LL y,LL p){
    LL ret=0;
    while(y){
        if(y&1)ret=(ret+x)%p;
        y>>=1;
        x=(x+x)%p;
    }
    return ret;
}

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

LL excrt(){
    LL M=1,ret=0;//最后返回的也是ret里面的余数,直接用ret表示余数,初始余数是0
    for(int i=1;i<=n;i++){//a为之前的m,b是新来的m
        LL a=M,b=m[i],c=r[i]-ret;
        //因为这里要exgcd,并且有溢出可能,要先改为最小非负整数
        c=(c%b+b)%b;

        LL x,y,d;
        d=exgcd(a,b,x,y);
        if(c%d != 0){//无解
            return -1;
        }
        
        LL k1=b/d;
        x=qmul(x,c/d,k1);
        x = (x%k1+k1)%k1;

        //把x通解形式带入进ret里面x
        ret=ret + x * M;
        M = M*k1;
        ret = (ret%M+M)%M;
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>m[i]>>r[i];
    cout<<excrt();
}