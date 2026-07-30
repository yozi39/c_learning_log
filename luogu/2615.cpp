#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;

const int N=40;
int a[N][N];

int main(){
    int n;cin>>n;
    int mid=(n+1)/2;

    a[1][mid]=1;
    unordered_map<int,PII> mp;
    mp[1]={1,mid};

    for(int i=2;i<=n*n;i++){
        if(mp[i - 1].first == 1 && mp[i-1].second != n){
            mp[i]={n,mp[i-1].second+1};
        } else if (mp[i - 1].first != 1 && mp[i-1].second == n){
            mp[i]={mp[i-1].first-1,1};
        } else if (mp[i-1].first==1 && mp[i-1].second==n){
            mp[i]={mp[i-1].first+1,mp[i-1].second};
        } else if (mp[i-1].first!=1 && mp[i-1].second!=n){
            if(a[mp[i-1].first-1][mp[i-1].second+1] == 0){
                mp[i]={mp[i-1].first-1,mp[i-1].second+1};
            } else {
                mp[i]={mp[i-1].first+1,mp[i-1].second};
            }
        }

        a[mp[i].first][mp[i].second]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}