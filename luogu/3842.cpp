#include<bits/stdc++.h>
using namespace std;

const int N=2e4+5;

int n;
int f[N][3];

struct node{
    int l,r;
}a[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
    }

    f[1][0]=2*a[1].r-a[1].l-1;
    f[1][1]=a[1].r-1;

    for(int i=2;i<=n;i++){
        f[i][0]=min(
            f[i-1][0]+abs(a[i-1].l-a[i].r),
            f[i-1][1]+abs(a[i-1].r-a[i].r)
        )+a[i].r-a[i].l+1;

        f[i][1]=min(
            f[i-1][0]+abs(a[i-1].l-a[i].l),
            f[i-1][1]+abs(a[i-1].r-a[i].l)
        )+a[i].r-a[i].l+1;
    }

    cout<<min(f[n][0]+n-a[n].l,f[n][1]+n-a[n].r);
}