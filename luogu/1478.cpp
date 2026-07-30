#include<bits/stdc++.h>
using namespace std;

const int N=5005;

int n,s;
int a,b;
struct P1478
{
    int h,f;
}ap[N];


int main(){
    cin>>n>>s>>a>>b;
    for(int i=1;i<=n;i++)cin>>ap[i].h>>ap[i].f;

    sort(ap+1,ap+n+1,
    [](const P1478& a,const P1478& b){
        if(a.f==b.f){
            return a.h<b.h;
        }
        return a.f<b.f;
    });

    int ret=0;
    for(int i=1;i<=n;i++){
        if(s<0) break;

        if(ap[i].h>a+b)continue;

        if(s<ap[i].f)continue;
        s-=ap[i].f;
        ret++;
    }

    cout<<ret;
}