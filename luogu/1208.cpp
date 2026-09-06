#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int n,m;

struct niunai{
    int p,a;
}milk[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>milk[i].p>>milk[i].a;

    sort(milk + 1, milk + m + 1,
        [](const niunai& a, const niunai& b) {
            return a.p < b.p;
        });

    long long current=0,sum=0;
    for(int i=1;i<=m;i++){
        if(n>=current+milk[i].a){
            current+=milk[i].a;
            sum+=milk[i].p*milk[i].a;
        }
        else{
            sum+=(n-current)*milk[i].p;
            break;
        }
    }
    cout<<sum;
}