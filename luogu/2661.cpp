#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,cnt;
int ne[N];//next
int in[N];
bool st[N];

void dfs(int x){
    cnt++;
    st[x]=true;

    int b=ne[x];
    if(!st[b])
        dfs(b);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ne[i];
        in[ne[i]]++;//计入度,因为拓扑排序可以去除其他不是环的部分
    }

    //拓扑排序
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        auto a=q.front();q.pop();
        st[a]=true;

        int b=ne[a];
        in[b]--;
        if(in[b]==0){
            q.push(b);
        }
    }

    //dfs 环大小
    int ret = n;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            cnt=0;//防止很多个环所以统计0
            dfs(i);
            ret=min(cnt,ret);
        }
    }

    cout<<ret;
}