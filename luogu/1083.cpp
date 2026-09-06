#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

int n,m;//day num;
int r[N];
int diff[N];

struct P1083{
    int s,e,d;
}t[N];

bool check(int k) {
    memset(diff, 0, sizeof(diff));

    for (int i = 1; i <= k; i++) {
        diff[t[i].s] += t[i].d;
        diff[t[i].e + 1] -= t[i].d;
    }

    long long need = 0;

    for (int day = 1; day <= n; day++) {
        need += diff[day];

        if (need > r[day]) {
            return false;
        }
    }

    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=m;i++){
        cin>>t[i].d>>t[i].s>>t[i].e;
    }

    if(check(m)){
        cout<<0;
        return 0;
    } else {
        cout<<-1<<'\n';
    }

    int left=1,right=n;
    while(left<right){
        int mid=(left+right)/2;
        if(!check(mid)){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }

    cout<<right;
}