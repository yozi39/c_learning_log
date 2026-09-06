#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=85;

int n,m;
int mp[N][N];
__int128 f[N][N];

void print(__int128 x){
    if(x==0){
        cout<<0;
        return;
    }

    string s;
    while(x){
        s+=x%10+'0';
        x/=10;
    }

    reverse(s.begin(),s.end());
    cout<<s;
}

__int128 qpow(int b){
    __int128 ret=1;
    __int128 a=2;
    while(b){
        if(b&1)ret = ret*a;
        b>>=1;
        a=a*a;
    }

    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    
    __int128 ret=0;
    for(int k=1;k<=n;k++){
        memset(f,0,sizeof f);
        for(int i=1;i<=m;i++){
            f[i][i]=(__int128)mp[k][i]*qpow(m);
        }

        for(int len=2;len<=m;len++){
            for(int i=1;i+len-1<=m;i++){
                int j=i+len-1;
                __int128 add=qpow(m-len+1);

                f[i][j]=max(
                    f[i+1][j]+(__int128)mp[k][i]*add,
                    f[i][j-1]+(__int128)mp[k][j]*add
                );
            }
        }

        ret+=f[1][m];
    }

    print(ret);
}