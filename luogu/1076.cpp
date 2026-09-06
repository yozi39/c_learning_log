#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e4+5,MOD=20123,M=110;

LL n,m;
bool st[N][M];
LL x[N][M],cnt[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int a,b;cin>>a>>b;
            if(a){
                st[i][j]=true;
                cnt[i]++;
            }
            x[i][j]=b;
        }
    }

    int pos=0;cin>>pos;
    LL ret=0;
    for(int i=1;i<=n;i++){
        ret+=x[i][pos]%MOD;
        LL step=x[i][pos]%cnt[i];
        if(!step){
            step=cnt[i];
        }

        while(true){
            if(st[i][pos])step--;
            if(step==0)break;
            pos++;
            if(pos==m)pos=0;
        }
    }

    cout<<ret%MOD<<'\n';
}