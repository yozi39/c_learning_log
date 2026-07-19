#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD=1e9+7,N=5;
LL n;

struct mat
{
    LL m[N][N];
    mat(){
        for(int i=1;i<N;i++){
            for(int j=1;j<N;j++){
                m[i][j]=0;
            }
        }
    }

    mat operator*(const mat&B)const{
        mat C;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                for(int k=1;k<=2;k++){
                    C.m[i][j]=(C.m[i][j]+(m[i][k]*B.m[k][j]%MOD)%MOD)%MOD;
                }
            }
        }
        return C;
    }
}A,RET;

void qpow(LL b){
    while (b)
    {
        if(b&1)RET=RET*A;
        b>>=1;
        A=A*A;
    }
}

int main(){
    cin>>n;
    if(n==1 || n==2){
        cout<<1;
        return 0;
    }
    A.m[1][1]=A.m[1][2]=A.m[2][1]=1;A.m[2][2]=0;
    RET.m[1][1]=RET.m[1][2]=1;RET.m[2][2]=RET.m[2][1]=0;

    qpow(n-2);

    cout<<RET.m[1][1];
}