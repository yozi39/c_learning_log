#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=2e5+5;

int n;
LL a[N];
unordered_set<LL> mp;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp.insert(x);
    }

    int cnt=1;
    for(auto v:mp){
        a[cnt]=v;
        cnt++;
    }

    sort(a+1,a+cnt,greater<int>());

    if(mp.size()>=3){
        cout << max(a[3], a[1] % a[2]);
    } else if(mp.size()==2) {
        cout<<a[2];
    } else {
        cout<<-1;
    }
}