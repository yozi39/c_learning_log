#include<bits/stdc++.h>
using namespace std;

const int N=25;
int n,ret;
string origin[N];
int cnt[N];

void dfs(string path){
    if(path.size()>ret) ret=path.size();

    for(int i=1;i<=n;i++){
        if(cnt[i]>=2)continue;

        int cur1=path.size()-1,cur2=0;
        while(cur1>=1 && cur2<origin[i].size()-1){
            if(path.substr(cur1)==origin[i].substr(0,cur2+1)){
                cnt[i]++;

                dfs(path+origin[i].substr(cur2+1));

                cnt[i]--;
            }

            cur1--;cur2++;
        }
    }
}

int main(){
    cin>>n;for(int i=1;i<=n;i++)cin>>origin[i];
    char ch;cin>>ch;

    for(int i = 1; i <= n; i++){
        if(origin[i].front() == ch){
            cnt[i]++;
            dfs(origin[i]);
            cnt[i]--;
        }
    }

    cout<<ret;
}