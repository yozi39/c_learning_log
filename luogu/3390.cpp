#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=110,MOD=1e9+7;

LL n,k;

struct mat
{
    LL m[N][N];
    //构造函数
    mat(){
        memset(m,0,sizeof m);
    }
    //重载乘法运算符
    mat operator*(const mat& B)const{
        mat C;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    C.m[i][j] = (C.m[i][j]+(m[i][k]*B.m[k][j]%MOD))%MOD;
                }
            }
        }
        return C;
    }
}A,RET;

void qpow(LL b){
    //变成单位矩阵
    for(int i=1;i<=n;i++){
        RET.m[i][i]=1;
    }
    while(b){
        if(b&1)RET = RET*A;
        b>>=1;
        A=A*A;
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A.m[i][j];
            A.m[i][j]%=MOD;
        }
    }

    qpow(k);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<RET.m[i][j]<<' ';
        }
        cout<<'\n';
    }
}