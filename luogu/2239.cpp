#include<bits/stdc++.h>
using namespace std;

const int N=3e4+5,
    dx[]={0,1,0,-1},
    dy[]={1,0,-1,0}
;

int dfs(int n,int begin,int i,int j){
    if(i == 1) return begin+j;
    else if (j==n) return begin+n+i-1;
    else if (i==n) return begin + 3*n-1-j;
    else if(j==1) return begin+4*n-2-i;

    return dfs(n-2,begin+4*(n-1),i-1,j-1);
}

int main(){
    int n,i,j;
    cin>>n>>i>>j;

    cout<<dfs(n,0,i,j);
}