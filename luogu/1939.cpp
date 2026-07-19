#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=5,MOD=1e9+7;

int n;

struct mat
{
    LL m[N][N];
    mat(){
        memset(m,0,sizeof m);
    }

    void clear(){
        memset(m,0,sizeof m);
    }

    mat operator*(const mat& B)const{
        mat C;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    C.m[i][j]=(C.m[i][j]+(m[i][k]*B.m[k][j]%MOD)%MOD)%MOD;
                }
            }
        }
        return C;
    }
}A,RET;

void qpow(LL b){
    for(int i=1;i<=3;i++){
        RET.m[1][i]=1;
    }
    A.m[1][1]=A.m[1][2]=A.m[2][3]=A.m[3][1]=1;
    while (b)
    {
        if(b&1)RET=RET*A;
        b>>=1;
        A=A*A;
    }
    
}

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n;
        if(n==1||n==2||n==3){
            cout<<1<<'\n';
            continue;
        }
        A.clear();
        RET.clear();
        qpow(n-3);
        cout<<RET.m[1][1]<<'\n';
    }
}