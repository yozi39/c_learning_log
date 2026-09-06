#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x & -x)

const int N=1e5+5,MOD=1e8-3;

int n;
struct node
{
    LL id,num;

    bool operator<(const node& other){
        return num<other.num;
    }
}a[N],b[N];
LL c[N],s[N];

LL query(int x){
    LL sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum=(sum+s[i])%MOD;
    }
    return sum%MOD;
}

void modify(int x){
    for(int i=x;i<=n;i+=lowbit(i)){
        s[i]++;
    }
}

int main(){
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>a[j].num;
        a[j].id=j;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].num;
        b[i].id=i;
    }

    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    for(int i=1;i<=n;i++){
        int sid=a[i].id,tid=b[i].id;
        c[sid]=tid;
    }

    LL ret=0;
    for(int i=1;i<=n;i++){
        ret=(ret+(query(n)-query(c[i])%MOD+MOD))%MOD;

        modify(c[i]);
    }
    cout<<ret;
}