#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
typedef long long LL;

const int N=5e5+5;

int n;
LL a[N],t[N];
int cnt;
LL s[N];
unordered_map<int,int> mp;

void modify(int x){
    for(int i=x;i<=cnt;i+=lowbit(i)){
        s[i]++;
    }
}

LL query(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=s[i];
    }
    return sum;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[i]=a[i];
    }

    sort(t+1,t+1+n);

    for(int i=1;i<=n;i++){
        if(!mp.count(t[i])){
            mp[t[i]]=++cnt;
        }
    }

    LL ret=0;
    for(int i=1;i<=n;i++){
        int x=mp[a[i]];
        int bcnt=query(x),acnt=query(cnt);
        ret+=acnt-bcnt;

        modify(x);
    }

    cout<<ret<<'\n';
}