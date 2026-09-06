#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n;
set<int> s[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        s[x].insert(i);
    }

    while(s[0].size() || s[1].size()){
        int p;
        
        if(s[1].empty() || (s[0].size() && *s[0].begin() < *s[1].begin()))p=0;
        else p=1;

        int x=0;
        while (1)
        {
            auto it=s[p].upper_bound(x);
            if(it == s[p].end())break;

            cout<<*it<<' ';
            x=*it;
            s[p].erase(it);
            p^=1;
        }
        cout<<'\n';
    }
}