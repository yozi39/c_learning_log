#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int n,ret[N];
struct P2926
{
    int id,n;
    bool operator<(P2926& b){
        return n<b.n;
    }
}a[N];
unordered_map<int,int> mp;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].n;
        mp[a[i].n]++;
    }
    
    for(int i=1;i<=n;i++){
        cout<<[&](int i){
            int ret=0;

            for(int j=1;j<=a[i].n/j;j++){
                if(a[i].n%j==0){
                    ret+=mp[j]+mp[a[i].n/j];

                    if(j==a[i].n/j)
                        ret-=mp[j];
                }
            }

            return ret-1;
        }(i)<<'\n';
    }
}