#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=30;
LL n,m;
LL p[N];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>p[i];

    LL ret=0;
    for(int st=1;st<(1<<n);st++){
        LL t=m,cnt=0;
        for(int i=0;i<n;i++){
            if((st>>i)&1){
                cnt++;
                t/=p[i];
            }
        }
        if(cnt%2==0)ret-=t;
        else ret+=t;
    }
    cout<<ret;
}