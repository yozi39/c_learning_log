#include<bits/stdc++.h>
using namespace std;

const int N=30;

int v,g;
int va[N],ga[N][N];

vector<int> need,bestneed;
int ret=0,ans=1e9;
bool st[N];

void dfs(int x){
    if(x>g){
        bool ok=true;
        for(int i=1;i<=v;i++){
            if(va[i]>0){
                ok=false;
                break;
            }
        }
        if(ok && ret<ans){
            ans=ret;
            bestneed=need;
        }

        return;
    }

    st[x]=true;
    for(int i=1;i<=v;i++){
        va[i]-=ga[x][i];
    }
    ret++;
    need.push_back(x);

    dfs(x+1);

    need.pop_back();
    ret--;
    st[x]=false;
    for(int i=1;i<=v;i++){
        va[i]+=ga[x][i];
    }

    dfs(x+1);
}

int main(){
    cin>>v;
    for(int i=1;i<=v;i++){
        cin>>va[i];
    }
    cin>>g;
    for(int i=1;i<=g;i++){
        for(int j=1;j<=v;j++){
            cin>>ga[i][j];
        }
    }

    dfs(1);

    cout<<ans<<' ';

    for(auto nnn:bestneed){
        cout<<nnn<<' ';
    }
}