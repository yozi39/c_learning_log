#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
int ans[1010];

int chuli(string x){
    if(x.size()==2){
        if(x=="SJ")return 15;
        if(x=="10")return 10;
        return 16;
    }

    else{
        switch (x[0])
        {
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return x[0]-'0';
        }
    }
}

int main(){
    int T;cin>>T;
    int end=T;
    while(T--){
        string a[18];
        for(int i=1;i<=17;i++){
            cin>>a[i];
            mp[chuli(a[i])]++;
        }
        
        int cnt=0;
        for(int i=3;i<=14;i++){
            if(mp[i]){
                cnt++;
            }
            else{
                cnt=0;
            }
            ans[T]=max(ans[T],cnt);
        }

        if(ans[T]<5)ans[T]=0;
        mp.clear();
    }

    T=end;
    while(T--){cout<<ans[T]<<'\n';}
}