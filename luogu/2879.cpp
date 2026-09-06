#include<bits/stdc++.h>
using namespace std;

const int N=10005;

int n,I,h,r;
int a[N],diff[N];
int e[2*N];

int main(){
    cin>>n>>I>>h>>r;
    for(int i=1;i<=r*2;i+=2){
        cin>>e[i]>>e[i+1];
    }
    for(int i=1;i<=n;i++){
        a[i]=h;
        diff[i]=a[i]-a[i-1];
    }

    set<pair<int,int>> st;

    for(int i=1;i<2*r;i+=2){
        int small=min(e[i],e[i+1]);
        int big=max(e[i],e[i+1]);

        if(st.count({small,big})) continue;
        st.insert({small,big});

        diff[small+1]--;
        diff[big]++; 
    }
    
    for(int i=1;i<=n;i++){
        a[i]=diff[i]+a[i-1];
        cout<<a[i]<<'\n';
    }
}