#include<bits/stdc++.h>
using namespace std;

const int N=1005;

int n,s,m,cnt[N];
struct P10710
{
    int h,id;
}a[N*N];

bool cmp(P10710& a,P10710& b){
    return a.h<b.h;
}

int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            m++;
            cin>>a[m].h;
            a[m].id=i;
        }
    }
    sort(a+1,a+1+m,cmp);

    int ret=1e9;
    for(int l=1,r=1,kind=0;r<=m;r++){
        cnt[a[r].id]++;
        if(cnt[a[r].id]==1)kind++;
        
        while(kind==n){
            ret=min(ret,a[r].h-a[l].h);
            cnt[a[l].id]--;
            if(cnt[a[l].id]==0)kind--;
            l++;
        }
    }
    cout<<ret;
}