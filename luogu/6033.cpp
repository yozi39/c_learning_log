#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e7+5,M=1e5+5;

int n;
int cnt[M];
LL q[N];
int now=1,head=1,tail=0;

LL getmin(){
    while(now<M && cnt[now]==0)now++;

    if(now==M)return q[head++];

    if(head>tail || now<=q[head]){
        cnt[now]--;
        return now;
    }

    return q[head++];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    LL ret=0;

    for(int i=1;i<n;i++){
        LL x=getmin();
        LL y=getmin();

        LL z=x+y;
        ret+=z;

        q[++tail]=z;
    }

    cout<<ret;
}