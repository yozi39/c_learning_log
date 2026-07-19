#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10,T=1e3;

LL f[N];
LL c[5],n;

void init(){
    f[0]=1;
    for(int i=1;i<=4;i++){//枚举物品
        for(int j=c[i];j<=1e5;j++){
            f[j]=f[j-c[i]]+f[j];
        }
    }
}

int main(){
    cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
    init();
    while(n--){
        LL d[5],s;cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;

        LL ret=0;
        for(int st=0;st<(1<<4);st++){
            LL cnt=0,sum=0;
            for(int i=1;i<=4;i++){
                if((st>>(i-1))&1){
                    cnt++;
                    sum+=(d[i]+1)*c[i];
                }
            }
            if(sum>s)continue;
            if(cnt%2==0){
                ret+=f[s-sum];
            }
            else{ret-=f[s-sum];}
        }
        cout<<ret<<'\n';
    }
}