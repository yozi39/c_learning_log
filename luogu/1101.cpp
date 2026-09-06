#include<bits/stdc++.h>
using namespace std;

const int N=105,
    dx[]={0,0,1,-1,1,1,-1,-1},
    dy[]={1,-1,0,0,1,-1,1,-1};

int n;
string s="yizhong";
char a[N][N],ret[N][N];

bool find(int x,int y,int k){
    for(int p=0;p<7;p++){
        int nx=x+dx[k]*p;
        int ny=y+dy[k]*p;

        if(nx<=0 || nx>n || ny<=0 || ny>n){
            return false;
        }

        if(a[nx][ny]!=s[p]){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            ret[i][j]='*';
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!='y') continue;

            for(int k=0;k<8;k++){
                if(find(i,j,k)){
                    for(int p=0;p<7;p++){
                        int nx=i+dx[k]*p;
                        int ny=j+dy[k]*p;
                        ret[nx][ny]=a[nx][ny];
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ret[i][j];
        }
        cout<<'\n';
    }
}