#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
using LL = long long;

const int N=1e3+5;

int n,h,r;
LL x[N],y[N],z[N];

bool canToDist(LL x1,LL y1,LL z1,LL x2,LL y2,LL z2,LL r){
    long long dx = x1 - x2;
    long long dy = y1 - y2;
    long long dz = z1 - z2;

    return dx * dx + dy * dy + dz * dz <= 4LL * r * r;
}

bool st[N];
bool dfs(int x,const vector<int> e[]){
    if(z[x]+r>=h){
        return true;
    }
    st[x]=true;

    for(int ne : e[x]){
        if(!st[ne]){
            if(dfs(ne,e)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int T;cin>>T;
    while(T--){
        memset(st, false, sizeof st);
        cin>>n>>h>>r;
        vector<int> e[N];
        for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>z[i];

        for(int i = 1; i <= n; i++){//建图
            for(int j = i + 1; j <= n; j++){
                if(canToDist(x[i], y[i], z[i],
                            x[j], y[j], z[j], r)){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }

        bool ok=false;
        for(int i = 1; i <= n; i++){
            if(z[i] <= r && !st[i]){
                if(dfs(i, e)){
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}