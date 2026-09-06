#include<bits/stdc++.h>
using namespace std;

int n,pos,sum;
vector<int> path[1000],curp;

void dfs(int x){
    if(x==n){
        if(curp.size()>1)
            path[++pos]=curp;
        return;
    }

    int start=curp.empty() ? 1 : curp.back();

    for(int i=start;i<=n;i++){
        if(x+i<=n){
            curp.push_back(i);

            dfs(x+i);

            curp.pop_back();
        }
    }
}

int main(){
    cin>>n;

    dfs(0);

    for(int i=1;i<=pos;i++){
        for(int j=0;j<path[i].size()-1;j++){
            cout<<path[i][j]<<'+';
        }   cout<<path[i][path[i].size()-1]<<'\n';
    }
}