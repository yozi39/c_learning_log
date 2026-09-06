#include<bits/stdc++.h>
using namespace std;

const int N=1010;

int n,m;
struct P3133
{
    int x,y;
}a[N],b[N];
int f[N][N];

int calcEmergy(int i,int j){
    return (a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
}

int main(){
    cin>>n>>m;
    cin>>a[0].x>>a[0].y;
    cin>>b[0].x>>b[0].y;

    for(int i=1;i<=n;i++){
        char ch;cin>>ch;
        if(ch=='N'){
            a[i]={a[i-1].x,a[i-1].y+1};
        } else if (ch=='S'){
            a[i]={a[i-1].x,a[i-1].y-1};
        } else if (ch=='W'){
            a[i]={a[i-1].x-1,a[i-1].y};
        } else {
            a[i]={a[i-1].x+1,a[i-1].y};
        }
    }
    
    for(int i=1;i<=m;i++){
        char ch;cin>>ch;
        if(ch=='N'){
            b[i]={b[i-1].x,b[i-1].y+1};
        } else if (ch=='S'){
            b[i]={b[i-1].x,b[i-1].y-1};
        } else if (ch=='W'){
            b[i]={b[i-1].x-1,b[i-1].y};
        } else {
            b[i]={b[i-1].x+1,b[i-1].y};
        }
    }

    for(int j=1;j<=m;j++)f[0][j]=f[0][j-1]+calcEmergy(0,j);
    for(int i=1;i<=n;i++)f[i][0]=f[i-1][0]+calcEmergy(i,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+calcEmergy(i,j);
        }
    }
    cout<<f[n][m];
}