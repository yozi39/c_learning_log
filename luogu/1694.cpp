#include<bits/stdc++.h>
using namespace std;

const int N=105,M=155;

int n,m,ret[N];
vector<int> edges[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int a=1;a<=n;a++){
        for(int i=1;i<=4;i++){
            bool flag=true;
            for(auto b:edges[a]){
                if(ret[b]==i){
                    flag=false;
                    break;
                }
            }

            if(flag){
                ret[a]=i;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++)cout<<ret[i];
}