#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N=10;
const int dx[4]={0,0,1,-1},dy[]={1,-1,0,0};

int a,b;
LL ret,retX,retY;
bool st[N][N];

void dfs(int i,int j){
    if(i<1 || i>=a || j<1 || j>=b){
        ret++;
        return;
    }

    st[i][j]=true;
    for(int k=0;k<4;k++){
        int x=i+dx[k],y=j+dy[k];
        
        if(!st[x][y]) dfs(x,y);
    }
    st[i][j]=false;
}

int main(){
    cin>>a>>b;
    int time=a*b/2;


    ret=retX+retY;
    for(int i=1;i<b;i++){
        st[0][i]=true;//直接从1,i开始搜索
        dfs(1,i);
        st[0][i]=false;
    }

    for(int i=1;i<a;i++){
        st[i][0]=true;
        dfs(i,1);
        st[i][0]=false;
    }

    cout<<ret;
}