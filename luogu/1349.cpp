#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1;
LL p,q,a1,a2,n,mod;

struct mat{
    LL m[5][5];
    mat(){
        memset(m,0,sizeof m);
    }
    mat operator*(mat& B){
        mat C;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                for(int k=1;k<=2;k++){
                    C.m[i][j] = (C.m[i][j]+(m[i][k]*B.m[k][j]%mod))%mod;
                }
            }
        }
        return C;
    }
}A,RET;

void qpow(LL b){
    RET.m[1][1]=a2;RET.m[1][2]=a1;
    while(b){
        if(b&1)RET=RET*A;
        b>>=1;
        A=A*A;
    }
}

int main(){
    cin>>p>>q>>a1>>a2>>n>>mod;
    A.m[1][1]=p;A.m[2][1]=q;A.m[1][2]=1;A.m[2][2]=0;

    if(n==1){
        cout<<a1%mod;
        return 0;
    }
    if(n==2){
        cout<<a2%mod;
        return 0;
    }
    
    qpow(n-2);

    cout<<RET.m[1][1];
}