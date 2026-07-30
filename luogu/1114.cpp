#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n;
unordered_map<int,int> mp;

int main(){
    cin>>n;
    int sum=0,ret=0;

    mp[0]=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;

        x = (x==0 ? -1:1);
        sum+=x;

        if(mp.count(sum)){
            ret=max(ret,i-mp[sum]);
        } else {
            mp[sum]=i;
        }
    }

    cout<<ret;
}