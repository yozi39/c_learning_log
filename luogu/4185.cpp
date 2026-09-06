#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,q;
struct video{
    int p,q,r;
}a[N];
struct question
{
    int k,v;
}b[N];


int main(){
    cin>>n>>q;
    for(int i=1;i<n;i++)cin>>a[i].p>>a[i].q>>a[i].r;
    for(int i=1;i<=q;i++)cin>>b[i].k>>b[i].v;

    
}