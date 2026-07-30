#include<bits/stdc++.h>
using namespace std;

const int N=105;
const int dx[]={0,0,1,-1,1,1,-1,-1},dy[]={1,-1,0,0,1,-1,1,-1};

int n,m,cnt;
char pan[N][N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>pan[i][j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j]=='*')continue;

            for(int k=0;k<8;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>0 && y>0 && x<=n && y<=m){
                    if(pan[x][y]=='*')cnt++;
                }
            }

            pan[i][j]=cnt+'0';
            cnt=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<pan[i][j];
        }
        cout<<'\n';
    }
}