#include<bits/stdc++.h>
using namespace std;

const int N=8005;

int n,q;
int op,x,y;
struct node{
    int id,n;

    bool operator<(node& b){
        if(n==b.n){
            return id<b.id;
        } else {
            return n<b.n;
        }
    }
}a[N];
int mp[N];

void getId(){
    for(int i=1;i<=n;i++){
        mp[a[i].id]=i;
    }
}

void bubble(){
    for(int i=2;i<=n;i++){
        if(a[i].n < a[i-1].n || (a[i].n==a[i-1].n && a[i].id<a[i-1].id)){
            swap(a[i],a[i-1]);
        }
    }

    for(int i=n;i>=2;i--){
        if(a[i].n < a[i-1].n || (a[i].n==a[i-1].n && a[i].id<a[i-1].id)){
            swap(a[i],a[i-1]);
        }
    }
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].n;
        a[i].id=i;
    }

    sort(a+1,a+1+n);
    getId();

    while(q--){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            a[mp[x]].n=y;
            bubble();
            getId();
        } else {
            cin>>x;
            cout<<mp[x]<<'\n';
        }
    }
}