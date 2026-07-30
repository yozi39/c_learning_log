#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n,r,q;

struct P1309
{
    int s,w,id;
}a[N];

P1309 x[N],y[N];//胜利和失败组

bool cmp(P1309& a,P1309& b){
    if(a.s == b.s){
        return a.id<b.id;
    } else {
        return a.s>b.s;
    }
}

void merge(){
    int cur1=1,cur2=1,i=1;
    while(cur1<=n && cur2<=n){
        if(x[cur1].s>y[cur2].s ||
            (x[cur1].s==y[cur2].s 
            && x[cur1].id<y[cur2].id)){
            a[i++]=x[cur1++];
        } else {
            a[i++]=y[cur2++];
        }
    }

    while(cur1<=n)a[i++]=x[cur1++];
    while(cur2<=n)a[i++]=y[cur2++];
}

int main(){
    cin>>n>>r>>q;
    for(int i=1;i<=2*n;i++){
        cin>>a[i].s;
        a[i].id=i;
    }
    for(int i=1;i<=2*n;i++)cin>>a[i].w;
    sort(a+1,a+1+2*n,cmp);

    while(r--){
        int pos=1;
        for(int i=1;i<=n+n;i+=2){
            if(a[i].w>a[i+1].w){
                a[i].s++;
                x[pos]=a[i];
                y[pos]=a[i+1];
            } else {
                a[i+1].s++;
                x[pos]=a[i+1];
                y[pos]=a[i];
            }
            pos++;
        }
        merge();
    }

    cout<<a[q].id;
}