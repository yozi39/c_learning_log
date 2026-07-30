#include<bits/stdc++.h>
using namespace std;
using LL=long long;
//p[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]
//a[i][j] = -(p[i][j] - p[i-1][j] - p[i][j-1] + p[i-1][j-1])
const int N=5e3+5;
int n,m,k;
int f[N][N];

void insert(int x1,int y1,int x2,int y2,int k){
    f[x1][y1]+=k;
    f[x1][y2+1]-=k;
    f[x2+1][y1]-=k;
    f[x2+1][y2+1]+=k;
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;

        insert(x,y,x,y,z);
    }

    LL ret=0;
    for(int x1=1;x1<=n-k+1;x1++){
        for(int y1=1;y1<=n-k+1;y1++){
            ret+=abs(f[x1][y1]);
            int x2=x1+k-1,y2=y1+k-1;
            insert(x1,y1,x2,y2,-f[x1][y1]);
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(f[i][j]!=0){
                cout<<-1;
                return 0;
            }
        }

    cout<<ret;
}