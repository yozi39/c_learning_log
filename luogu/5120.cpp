#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n;

struct cow{
    LL a,t;
    int id;
}a[N];

bool comp(const cow& x,const cow& y){
    return x.a<y.a;
}

struct cmp{
    bool operator()(const cow& x,const cow& y) const{
        return x.id>y.id;
    }
};

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].t;
        a[i].id=i;
    }

    sort(a+1,a+n+1,comp);

    priority_queue<cow,vector<cow>,cmp> q;

    LL ret=0,time=a[1].a;
    int pos=1,cnt=0;

    while(cnt<n){
        if(q.empty()){
            time=max(time,a[pos].a);
        }

        while(pos<=n && a[pos].a<=time){
            q.push(a[pos]);
            pos++;
        }

        auto x=q.top();
        q.pop();

        ret=max(ret,time-x.a);
        time+=x.t;
        cnt++;
    }

    cout<<ret;
}